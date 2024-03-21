# Uncomment the next line to define a global platform for your project
platform :ios, '11.0'
source 'https://cdn.cocoapods.org/'
source 'https://github.com/TuyaInc/TuyaPublicSpecs.git'
source 'https://github.com/tuya/tuya-pod-specs.git'

target 'MyTestApp' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

#	pod 'TYSmartSceneModule', :podspec => 'https://images.tuyacn.com/smart/app/package/developer/sdk/1689216927/TYSmartSceneModule.podspec.json'
# 	pod 'TuyaSmartSceneBizBundle', '3.34.5.7'
  
#    pod 'TuyaSmartCameraKit'
#    pod 'TuyaCommunityKit'
#    pod 'TuyaSmartHomeKit'
#    pod 'TuyaCommunityThirdLoginKit' ,
#    :podspec=>'https://images.tuyacn.com/smart/app/package/developer/sdk/1661156323/TuyaCommunityThirdLoginKit.podspec.json'
    
#    pod 'TuyaSmartPanelBizBundle','~> 3.34.5'
#    pod 'TuyaSmartSceneBizBundle','3.34.5.7'
#    pod 'TuyaSmartActivatorBizBundle','~> 3.34.5.9'
#    pod 'TuyaSmartSpeechBizBundle','~> 3.34.5'
#    pod 'TuyaSmartDeviceSyncBizBundle','~> 3.34.5.6'
#    pod 'TuyaSmartFamilyBizBundle','~> 3.34.5'
#    pod 'TuyaSmartSceneBizBundle', :path => './TuyaSmartSceneBizBundle.podspec.json'
  #  pod 'TYSmartSceneModule', :podspec => 'https://images.tuyacn.com/smart/app/package/developer/sdk/1685412341/TYSmartSceneModule.podspec.json'
#    pod 'TYSmartSceneModule', :podspec => 'https://images.tuyacn.com/smart/app/package/developer/sdk/1689216927/TYSmartSceneModule.podspec.json'

pod 'TYFoundationKit', '1.16.2'
    
  

end


post_install do |installer|
  pod_targets = installer.generated_projects.map(&:targets).flatten.compact.uniq
  installer.aggregate_targets.map(&:user_project).compact.uniq.each do |project|
    ((project.respond_to?(:targets) ? project.targets : []) + pod_targets).each do |target|
      next unless target.is_a?(Xcodeproj::Project::Object::PBXNativeTarget)
      if target.launchable_target_type? || target.extension_target_type?
        target.build_configurations.each do |config|
          config.build_settings.delete_if { |k| k.start_with?('EXCLUDED_ARCHS') }
          if target.platform_name == :ios
            # iOS 真机包只包含 arm64
            config.build_settings["ARCHS[sdk=iphoneos*]"] = "arm64"
            # iOS 模拟器去除 arm64
            config.build_settings["EXCLUDED_ARCHS[sdk=iphonesimulator*]"] = "arm64"
            # Xcode 14 编译问题
            config.build_settings["DEVELOPMENT_TEAM"] = "94JFPTRDN5"
            # Xcode 14 编译问题
            config.build_settings['ENABLE_BITCODE'] = 'NO'
          end
          if target.platform_name == :watchos
            # watchOS 模拟器去除 arm64 x86_64
            config.build_settings["EXCLUDED_ARCHS[sdk=watchsimulator*]"] = "arm64 x86_64"
            # Xcode 14 编译问题
            config.build_settings['ENABLE_BITCODE'] = 'NO'
          end
        end
      end
    end
  end
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings['APPLICATION_EXTENSION_API_ONLY'] = 'NO'
      config.build_settings["EXCLUDED_ARCHS[sdk=iphonesimulator*]"] = "arm64"
      config.build_settings.delete("IPHONEOS_DEPLOYMENT_TARGET")
      # Xcode 14 编译问题
      config.build_settings["DEVELOPMENT_TEAM"] = "94JFPTRDN5"
      # Xcode 14 编译问题
      config.build_settings['ENABLE_BITCODE'] = 'NO'
    end
  end
  # 多工程模式下，pods_project 只包含 aggregate_targets，不包含 pod_targets，这里是兜底
  installer.pod_target_subprojects.each do |subproject|
    subproject.targets.each do |sub_target|
      sub_target.build_configurations.each do |config|
        config.build_settings['APPLICATION_EXTENSION_API_ONLY'] = 'NO'
        config.build_settings["EXCLUDED_ARCHS[sdk=iphonesimulator*]"] = "arm64"
        config.build_settings.delete("IPHONEOS_DEPLOYMENT_TARGET")
        # Xcode 14 编译问题
        config.build_settings["DEVELOPMENT_TEAM"] = "94JFPTRDN5"
        # Xcode 14 编译问题
        config.build_settings['ENABLE_BITCODE'] = 'NO'
      end
    end
  end
  installer.pods_project.targets.each do |target|
    compatibilityPhase = target.build_phases.find { |ph| ph.display_name == 'Copy generated compatibility header' }
    if compatibilityPhase
      build_phase = target.new_shell_script_build_phase('Copy Swift Generated Header')
      build_phase.shell_script = <<-SH.strip_heredoc
            COMPATIBILITY_HEADER_PATH="${BUILT_PRODUCTS_DIR}/Swift Compatibility Header/${PRODUCT_MODULE_NAME}-Swift.h"
            ditto "${COMPATIBILITY_HEADER_PATH}" "${PODS_ROOT}/Headers/Public/${PRODUCT_MODULE_NAME}/${PRODUCT_MODULE_NAME}-Swift.h"
      SH
    end
  end
  # 混淆
#  system("sh #{File.dirname(__FILE__)}/Pods/ThingObfuscate/scripts/prepare_command.sh") or exit(1)
  # 删除 xcconfig 文件中的 WatchKit
#  `/usr/bin/sed -i '' 's/-framework "WatchKit"//g' Pods/Target\\ Support\\ Files/Pods-*/*.xcconfig`
end
