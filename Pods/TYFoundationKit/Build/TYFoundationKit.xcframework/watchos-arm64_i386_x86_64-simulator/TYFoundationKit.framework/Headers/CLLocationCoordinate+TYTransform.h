//
//  CLLocationCoordinate+TYTransform.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/5/16.
//



#import <CoreLocation/CLLocation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 GCJ-02: 中国国测局地理坐标（火星坐标）
 a geodetic datum formulated by the Chinese State Bureau of Surveying and Mapping
 
 BD-09: 百度地图坐标系
 a geographic coordinate system used by Baidu Maps
 
 WGS84: 世界标准地理坐标
 The World Geodetic System
 */


/**
 convert WGS84 to GCJ02 if in China
 */
FOUNDATION_EXTERN CLLocationCoordinate2D TY_CoordinateWGS84ToGCJ02(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D TY_CoordinateGCJ02ToWGS84(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D TY_CoordinateWGS84ToBD09(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D TY_CoordinateGCJ02ToBD09(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D TY_CoordinateBD09ToGCJ02(CLLocationCoordinate2D location);
FOUNDATION_EXTERN CLLocationCoordinate2D TY_CoordinateBD09ToWGS84(CLLocationCoordinate2D location);

NS_ASSUME_NONNULL_END
