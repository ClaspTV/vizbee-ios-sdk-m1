// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "VizbeeKit",
    platforms: [
        .iOS(.v10)
    ],
    products: [
        .library(
            name: "VizbeeKit",
            targets: ["VizbeeKit"])
    ],
    targets: [
        .binaryTarget(
            name: "VizbeeKit",
            path: "VizbeeKit.xcframework")
    ])
