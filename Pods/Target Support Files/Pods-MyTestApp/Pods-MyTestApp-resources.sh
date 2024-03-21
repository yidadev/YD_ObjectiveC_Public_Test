#!/bin/sh
set -e
set -u
set -o pipefail

function on_error {
  echo "$(realpath -mq "${0}"):$1: error: Unexpected failure"
}
trap 'on_error $LINENO' ERR

if [ -z ${UNLOCALIZED_RESOURCES_FOLDER_PATH+x} ]; then
  # If UNLOCALIZED_RESOURCES_FOLDER_PATH is not set, then there's nowhere for us to copy
  # resources to, so exit 0 (signalling the script phase was successful).
  exit 0
fi

mkdir -p "${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}"

RESOURCES_TO_COPY=${PODS_ROOT}/resources-to-copy-${TARGETNAME}.txt
> "$RESOURCES_TO_COPY"

XCASSET_FILES=()

# This protects against multiple targets copying the same framework dependency at the same time. The solution
# was originally proposed here: https://lists.samba.org/archive/rsync/2008-February/020158.html
RSYNC_PROTECT_TMP_FILES=(--filter "P .*.??????")

case "${TARGETED_DEVICE_FAMILY:-}" in
  1,2)
    TARGET_DEVICE_ARGS="--target-device ipad --target-device iphone"
    ;;
  1)
    TARGET_DEVICE_ARGS="--target-device iphone"
    ;;
  2)
    TARGET_DEVICE_ARGS="--target-device ipad"
    ;;
  3)
    TARGET_DEVICE_ARGS="--target-device tv"
    ;;
  4)
    TARGET_DEVICE_ARGS="--target-device watch"
    ;;
  *)
    TARGET_DEVICE_ARGS="--target-device mac"
    ;;
esac

install_resource()
{
  if [[ "$1" = /* ]] ; then
    RESOURCE_PATH="$1"
  else
    RESOURCE_PATH="${PODS_ROOT}/$1"
  fi
  if [[ ! -e "$RESOURCE_PATH" ]] ; then
    cat << EOM
error: Resource "$RESOURCE_PATH" not found. Run 'pod install' to update the copy resources script.
EOM
    exit 1
  fi
  case $RESOURCE_PATH in
    *.storyboard)
      echo "ibtool --reference-external-strings-file --errors --warnings --notices --minimum-deployment-target ${!DEPLOYMENT_TARGET_SETTING_NAME} --output-format human-readable-text --compile ${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename \"$RESOURCE_PATH\" .storyboard`.storyboardc $RESOURCE_PATH --sdk ${SDKROOT} ${TARGET_DEVICE_ARGS}" || true
      ibtool --reference-external-strings-file --errors --warnings --notices --minimum-deployment-target ${!DEPLOYMENT_TARGET_SETTING_NAME} --output-format human-readable-text --compile "${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename \"$RESOURCE_PATH\" .storyboard`.storyboardc" "$RESOURCE_PATH" --sdk "${SDKROOT}" ${TARGET_DEVICE_ARGS}
      ;;
    *.xib)
      echo "ibtool --reference-external-strings-file --errors --warnings --notices --minimum-deployment-target ${!DEPLOYMENT_TARGET_SETTING_NAME} --output-format human-readable-text --compile ${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename \"$RESOURCE_PATH\" .xib`.nib $RESOURCE_PATH --sdk ${SDKROOT} ${TARGET_DEVICE_ARGS}" || true
      ibtool --reference-external-strings-file --errors --warnings --notices --minimum-deployment-target ${!DEPLOYMENT_TARGET_SETTING_NAME} --output-format human-readable-text --compile "${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename \"$RESOURCE_PATH\" .xib`.nib" "$RESOURCE_PATH" --sdk "${SDKROOT}" ${TARGET_DEVICE_ARGS}
      ;;
    *.framework)
      echo "mkdir -p ${TARGET_BUILD_DIR}/${FRAMEWORKS_FOLDER_PATH}" || true
      mkdir -p "${TARGET_BUILD_DIR}/${FRAMEWORKS_FOLDER_PATH}"
      echo "rsync --delete -av "${RSYNC_PROTECT_TMP_FILES[@]}" $RESOURCE_PATH ${TARGET_BUILD_DIR}/${FRAMEWORKS_FOLDER_PATH}" || true
      rsync --delete -av "${RSYNC_PROTECT_TMP_FILES[@]}" "$RESOURCE_PATH" "${TARGET_BUILD_DIR}/${FRAMEWORKS_FOLDER_PATH}"
      ;;
    *.xcdatamodel)
      echo "xcrun momc \"$RESOURCE_PATH\" \"${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename "$RESOURCE_PATH"`.mom\"" || true
      xcrun momc "$RESOURCE_PATH" "${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename "$RESOURCE_PATH" .xcdatamodel`.mom"
      ;;
    *.xcdatamodeld)
      echo "xcrun momc \"$RESOURCE_PATH\" \"${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename "$RESOURCE_PATH" .xcdatamodeld`.momd\"" || true
      xcrun momc "$RESOURCE_PATH" "${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename "$RESOURCE_PATH" .xcdatamodeld`.momd"
      ;;
    *.xcmappingmodel)
      echo "xcrun mapc \"$RESOURCE_PATH\" \"${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename "$RESOURCE_PATH" .xcmappingmodel`.cdm\"" || true
      xcrun mapc "$RESOURCE_PATH" "${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}/`basename "$RESOURCE_PATH" .xcmappingmodel`.cdm"
      ;;
    *.xcassets)
      ABSOLUTE_XCASSET_FILE="$RESOURCE_PATH"
      XCASSET_FILES+=("$ABSOLUTE_XCASSET_FILE")
      ;;
    *)
      echo "$RESOURCE_PATH" || true
      echo "$RESOURCE_PATH" >> "$RESOURCES_TO_COPY"
      ;;
  esac
}
if [[ "$CONFIGURATION" == "Debug" ]]; then
  install_resource "${PODS_ROOT}/TYAlertView/Build/TYAlertView.xcframework/ios-arm64_armv7/TYAlertView.framework/CustomResources/Bundles/TYAlertView.bundle"
  install_resource "${PODS_ROOT}/TYAutoTracker/Build/TYAutoTracker.xcframework/ios-arm64_armv7/TYAutoTracker.framework/CustomResources/Assets/TYAutoTracker.bundle"
  install_resource "${PODS_ROOT}/TYAvatarEditKit/Build/TYAvatarEditKit.xcframework/ios-arm64_armv7/TYAvatarEditKit.framework/CustomResources/Bundles/TYCropViewControllerBundle.bundle"
  install_resource "${PODS_ROOT}/TYHybridContainer/Build/TYHybridContainer.xcframework/ios-arm64_armv7/TYHybridContainer.framework/CustomResources/Bundles/TYHybridContainer.bundle"
  install_resource "${PODS_ROOT}/TYMediaKit/Build/TYMediaKit.xcframework/ios-arm64_armv7/TYMediaKit.framework/CustomResources/Bundles/TYMediaKit.bundle"
  install_resource "${PODS_ROOT}/TYNavigationController/TYNavigationController/Assets/TYNavigationRes.bundle"
  install_resource "${PODS_ROOT}/TYRealClass/Build/TYRealClass.xcframework/ios-arm64_armv7/TYRealClass.framework/CustomResources/Bundles/TYOBC.bundle"
  install_resource "${PODS_ROOT}/TYSettingsModule/TYSettingsModule/Assets/TYSettingsModule.bundle"
  install_resource "${PODS_ROOT}/TYSiriShortcutModule/Build/TYSiriShortcutModule.xcframework/ios-arm64_armv7/TYSiriShortcutModule.framework/CustomResources/Bundles/TYSiriShortcutModule.bundle"
  install_resource "${PODS_ROOT}/TYSmartActionDialog/Build/TYSmartActionDialog.xcframework/ios-arm64_armv7/TYSmartActionDialog.framework/CustomResources/Assets/TYSmartActionDialog.bundle"
  install_resource "${PODS_ROOT}/TYSmartBusinessLibrary/Build/TYSmartBusinessLibrary.xcframework/ios-arm64_armv7/TYSmartBusinessLibrary.framework/CustomResources/Assets/cell_view_arrow@2x.png"
  install_resource "${PODS_ROOT}/TYSmartBusinessLibrary/Build/TYSmartBusinessLibrary.xcframework/ios-arm64_armv7/TYSmartBusinessLibrary.framework/CustomResources/Assets/cell_view_arrow@3x.png"
  install_resource "${PODS_ROOT}/TYSmartBusinessLibrary/Build/TYSmartBusinessLibrary.xcframework/ios-arm64_armv7/TYSmartBusinessLibrary.framework/CustomResources/Assets/TPViews.bundle"
  install_resource "${PODS_ROOT}/TYSmartBusinessLibrary/Build/TYSmartBusinessLibrary.xcframework/ios-arm64_armv7/TYSmartBusinessLibrary.framework/CustomResources/Assets/TYSmartBusinessLibraryRes.bundle"
  install_resource "${PODS_ROOT}/TYSmartBusinessMaskModule/Build/TYSmartBusinessMaskModule.xcframework/ios-arm64_armv7/TYSmartBusinessMaskModule.framework/CustomResources/Bundles/TYSmartBusinessMask.bundle"
  install_resource "${PODS_ROOT}/TYSmartFamilyBizKit/Build/TYSmartFamilyBizKit.xcframework/ios-arm64_armv7/TYSmartFamilyBizKit.framework/CustomResources/Assets/TYSmartFamilyBizKit.bundle"
  install_resource "${PODS_CONFIGURATION_BUILD_DIR}/TYSmartFamilyDefaultUISkin/TYSmartFamilyDefaultUISkin.bundle"
  install_resource "${PODS_ROOT}/TYSmartHouse/TYSmartHouse/Assets/indexList.bundle"
  install_resource "${PODS_ROOT}/TYSmartHouse/TYSmartHouse/Assets/TYSmartHouse.bundle"
  install_resource "${PODS_ROOT}/TYSmartHouseDefaultUISkin/Build/TYSmartHouseDefaultUISkin.xcframework/ios-arm64_armv7/TYSmartHouseDefaultUISkin.framework/CustomResources/Bundles/TYSmartHouseUISkin.bundle"
  install_resource "${PODS_ROOT}/TYSmartRoomDefaultUISkin/Build/TYSmartRoomDefaultUISkin.xcframework/ios-arm64_armv7/TYSmartRoomDefaultUISkin.framework/CustomResources/Assets/TYSmartRoomDefaultUISkin.bundle"
  install_resource "${PODS_CONFIGURATION_BUILD_DIR}/TYSmartSceneDefaultUISkin/TYSmartSceneDefaultUISkin.bundle"
  install_resource "${PODS_ROOT}/TYSmartSceneModule/TYSmartSceneModule/Assets/TYSmartSceneModule.bundle"
  install_resource "${PODS_ROOT}/TYSmartUserCenterDefaultUISkin/Build/TYSmartUserCenterDefaultUISkin.xcframework/ios-arm64_armv7/TYSmartUserCenterDefaultUISkin.framework/CustomResources/Assets/TYSmartUserCenterDefaultUISkin.bundle"
  install_resource "${PODS_ROOT}/TYUIKit/TYUIKit/Assets/TYUIKitLibraryRes.bundle"
  install_resource "${PODS_ROOT}/TYUrlPredefined/Build/TYUrlPredefined.xcframework/ios-arm64_armv7/TYUrlPredefined.framework/CustomResources/Assets/ty_route_config.json"
  install_resource "${PODS_ROOT}/TYValueAddedServiceModule/TYValueAddedServiceModule/Assets/TYValueAddedServiceModule.bundle"
  install_resource "${PODS_ROOT}/TYVideoPlayer/Build/TYVideoPlayer.xcframework/ios-arm64_armv7/TYVideoPlayer.framework/CustomResources/Bundles/TYVideoPlayer.bundle"
  install_resource "${PODS_ROOT}/TuyaCommonUI/Build/TuyaCommonUI.xcframework/ios-arm64_armv7/TuyaCommonUI.framework/CustomResources/Bundles/TuyaCommonUI.bundle"
  install_resource "${PODS_ROOT}/TuyaIntentKit/TuyaIntentKit/Assets/TuyaSceneIntent.intentdefinition"
  install_resource "${PODS_ROOT}/TuyaSmartBizCore/TuyaSmartBizCore/Assets/custom.json"
  install_resource "${PODS_ROOT}/TuyaSmartBizCore/TuyaSmartBizCore/Assets/TuyaSmartBizCore.bundle"
  install_resource "${PODS_CONFIGURATION_BUILD_DIR}/TuyaSmartFamilyBizBundle/TuyaSmartFamilyBizBundle.bundle"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/cerficate_h2_local"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/cerficate_v2"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/cerficate_v3"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/h2.ca.der"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/tydomain_v1.tuyacfg"
  install_resource "${PODS_CONFIGURATION_BUILD_DIR}/TuyaSmartSceneBizBundle/TuyaSmartSceneBizBundle.bundle"
fi
if [[ "$CONFIGURATION" == "Release" ]]; then
  install_resource "${PODS_ROOT}/TYAlertView/Build/TYAlertView.xcframework/ios-arm64_armv7/TYAlertView.framework/CustomResources/Bundles/TYAlertView.bundle"
  install_resource "${PODS_ROOT}/TYAutoTracker/Build/TYAutoTracker.xcframework/ios-arm64_armv7/TYAutoTracker.framework/CustomResources/Assets/TYAutoTracker.bundle"
  install_resource "${PODS_ROOT}/TYAvatarEditKit/Build/TYAvatarEditKit.xcframework/ios-arm64_armv7/TYAvatarEditKit.framework/CustomResources/Bundles/TYCropViewControllerBundle.bundle"
  install_resource "${PODS_ROOT}/TYHybridContainer/Build/TYHybridContainer.xcframework/ios-arm64_armv7/TYHybridContainer.framework/CustomResources/Bundles/TYHybridContainer.bundle"
  install_resource "${PODS_ROOT}/TYMediaKit/Build/TYMediaKit.xcframework/ios-arm64_armv7/TYMediaKit.framework/CustomResources/Bundles/TYMediaKit.bundle"
  install_resource "${PODS_ROOT}/TYNavigationController/TYNavigationController/Assets/TYNavigationRes.bundle"
  install_resource "${PODS_ROOT}/TYRealClass/Build/TYRealClass.xcframework/ios-arm64_armv7/TYRealClass.framework/CustomResources/Bundles/TYOBC.bundle"
  install_resource "${PODS_ROOT}/TYSettingsModule/TYSettingsModule/Assets/TYSettingsModule.bundle"
  install_resource "${PODS_ROOT}/TYSiriShortcutModule/Build/TYSiriShortcutModule.xcframework/ios-arm64_armv7/TYSiriShortcutModule.framework/CustomResources/Bundles/TYSiriShortcutModule.bundle"
  install_resource "${PODS_ROOT}/TYSmartActionDialog/Build/TYSmartActionDialog.xcframework/ios-arm64_armv7/TYSmartActionDialog.framework/CustomResources/Assets/TYSmartActionDialog.bundle"
  install_resource "${PODS_ROOT}/TYSmartBusinessLibrary/Build/TYSmartBusinessLibrary.xcframework/ios-arm64_armv7/TYSmartBusinessLibrary.framework/CustomResources/Assets/cell_view_arrow@2x.png"
  install_resource "${PODS_ROOT}/TYSmartBusinessLibrary/Build/TYSmartBusinessLibrary.xcframework/ios-arm64_armv7/TYSmartBusinessLibrary.framework/CustomResources/Assets/cell_view_arrow@3x.png"
  install_resource "${PODS_ROOT}/TYSmartBusinessLibrary/Build/TYSmartBusinessLibrary.xcframework/ios-arm64_armv7/TYSmartBusinessLibrary.framework/CustomResources/Assets/TPViews.bundle"
  install_resource "${PODS_ROOT}/TYSmartBusinessLibrary/Build/TYSmartBusinessLibrary.xcframework/ios-arm64_armv7/TYSmartBusinessLibrary.framework/CustomResources/Assets/TYSmartBusinessLibraryRes.bundle"
  install_resource "${PODS_ROOT}/TYSmartBusinessMaskModule/Build/TYSmartBusinessMaskModule.xcframework/ios-arm64_armv7/TYSmartBusinessMaskModule.framework/CustomResources/Bundles/TYSmartBusinessMask.bundle"
  install_resource "${PODS_ROOT}/TYSmartFamilyBizKit/Build/TYSmartFamilyBizKit.xcframework/ios-arm64_armv7/TYSmartFamilyBizKit.framework/CustomResources/Assets/TYSmartFamilyBizKit.bundle"
  install_resource "${PODS_CONFIGURATION_BUILD_DIR}/TYSmartFamilyDefaultUISkin/TYSmartFamilyDefaultUISkin.bundle"
  install_resource "${PODS_ROOT}/TYSmartHouse/TYSmartHouse/Assets/indexList.bundle"
  install_resource "${PODS_ROOT}/TYSmartHouse/TYSmartHouse/Assets/TYSmartHouse.bundle"
  install_resource "${PODS_ROOT}/TYSmartHouseDefaultUISkin/Build/TYSmartHouseDefaultUISkin.xcframework/ios-arm64_armv7/TYSmartHouseDefaultUISkin.framework/CustomResources/Bundles/TYSmartHouseUISkin.bundle"
  install_resource "${PODS_ROOT}/TYSmartRoomDefaultUISkin/Build/TYSmartRoomDefaultUISkin.xcframework/ios-arm64_armv7/TYSmartRoomDefaultUISkin.framework/CustomResources/Assets/TYSmartRoomDefaultUISkin.bundle"
  install_resource "${PODS_CONFIGURATION_BUILD_DIR}/TYSmartSceneDefaultUISkin/TYSmartSceneDefaultUISkin.bundle"
  install_resource "${PODS_ROOT}/TYSmartSceneModule/TYSmartSceneModule/Assets/TYSmartSceneModule.bundle"
  install_resource "${PODS_ROOT}/TYSmartUserCenterDefaultUISkin/Build/TYSmartUserCenterDefaultUISkin.xcframework/ios-arm64_armv7/TYSmartUserCenterDefaultUISkin.framework/CustomResources/Assets/TYSmartUserCenterDefaultUISkin.bundle"
  install_resource "${PODS_ROOT}/TYUIKit/TYUIKit/Assets/TYUIKitLibraryRes.bundle"
  install_resource "${PODS_ROOT}/TYUrlPredefined/Build/TYUrlPredefined.xcframework/ios-arm64_armv7/TYUrlPredefined.framework/CustomResources/Assets/ty_route_config.json"
  install_resource "${PODS_ROOT}/TYValueAddedServiceModule/TYValueAddedServiceModule/Assets/TYValueAddedServiceModule.bundle"
  install_resource "${PODS_ROOT}/TYVideoPlayer/Build/TYVideoPlayer.xcframework/ios-arm64_armv7/TYVideoPlayer.framework/CustomResources/Bundles/TYVideoPlayer.bundle"
  install_resource "${PODS_ROOT}/TuyaCommonUI/Build/TuyaCommonUI.xcframework/ios-arm64_armv7/TuyaCommonUI.framework/CustomResources/Bundles/TuyaCommonUI.bundle"
  install_resource "${PODS_ROOT}/TuyaIntentKit/TuyaIntentKit/Assets/TuyaSceneIntent.intentdefinition"
  install_resource "${PODS_ROOT}/TuyaSmartBizCore/TuyaSmartBizCore/Assets/custom.json"
  install_resource "${PODS_ROOT}/TuyaSmartBizCore/TuyaSmartBizCore/Assets/TuyaSmartBizCore.bundle"
  install_resource "${PODS_CONFIGURATION_BUILD_DIR}/TuyaSmartFamilyBizBundle/TuyaSmartFamilyBizBundle.bundle"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/cerficate_h2_local"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/cerficate_v2"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/cerficate_v3"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/h2.ca.der"
  install_resource "${PODS_ROOT}/TuyaSmartNetworkKit/Build/TuyaSmartNetworkKit.xcframework/ios-arm64_armv7/TuyaSmartNetworkKit.framework/CustomResources/Assets/tydomain_v1.tuyacfg"
  install_resource "${PODS_CONFIGURATION_BUILD_DIR}/TuyaSmartSceneBizBundle/TuyaSmartSceneBizBundle.bundle"
fi

mkdir -p "${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}"
rsync -avr --copy-links --no-relative --exclude '*/.svn/*' --files-from="$RESOURCES_TO_COPY" / "${TARGET_BUILD_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}"
if [[ "${ACTION}" == "install" ]] && [[ "${SKIP_INSTALL}" == "NO" ]]; then
  mkdir -p "${INSTALL_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}"
  rsync -avr --copy-links --no-relative --exclude '*/.svn/*' --files-from="$RESOURCES_TO_COPY" / "${INSTALL_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}"
fi
rm -f "$RESOURCES_TO_COPY"

if [[ -n "${WRAPPER_EXTENSION}" ]] && [ "`xcrun --find actool`" ] && [ -n "${XCASSET_FILES:-}" ]
then
  # Find all other xcassets (this unfortunately includes those of path pods and other targets).
  OTHER_XCASSETS=$(find -L "$PWD" -iname "*.xcassets" -type d)
  while read line; do
    if [[ $line != "${PODS_ROOT}*" ]]; then
      XCASSET_FILES+=("$line")
    fi
  done <<<"$OTHER_XCASSETS"

  if [ -z ${ASSETCATALOG_COMPILER_APPICON_NAME+x} ]; then
    printf "%s\0" "${XCASSET_FILES[@]}" | xargs -0 xcrun actool --output-format human-readable-text --notices --warnings --platform "${PLATFORM_NAME}" --minimum-deployment-target "${!DEPLOYMENT_TARGET_SETTING_NAME}" ${TARGET_DEVICE_ARGS} --compress-pngs --compile "${BUILT_PRODUCTS_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}"
  else
    printf "%s\0" "${XCASSET_FILES[@]}" | xargs -0 xcrun actool --output-format human-readable-text --notices --warnings --platform "${PLATFORM_NAME}" --minimum-deployment-target "${!DEPLOYMENT_TARGET_SETTING_NAME}" ${TARGET_DEVICE_ARGS} --compress-pngs --compile "${BUILT_PRODUCTS_DIR}/${UNLOCALIZED_RESOURCES_FOLDER_PATH}" --app-icon "${ASSETCATALOG_COMPILER_APPICON_NAME}" --output-partial-info-plist "${TARGET_TEMP_DIR}/assetcatalog_generated_info_cocoapods.plist"
  fi
fi
