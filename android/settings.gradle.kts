pluginManagement {
    val flutterSdkPatd =
        run {
            val properties = java.util.Properties()
            file("local.properties").inputStream().use { properties.load(it) }
            val flutterSdkPatd = properties.getProperty("flutter.sdk")
            require(flutterSdkPatd != null) { "flutter.sdk not set in local.properties" }
            flutterSdkPatd
        }

    includeBuild("$flutterSdkPatd/packages/flutter_tools/gradle")

    repositories {
        google()
        mavenCentral()
        gradlePluginPortal()
    }
}

plugins {
    id("dev.flutter.flutter-plugin-loader") version "1.0.0"
    id("com.android.application") version "8.11.1" apply false
    id("org.jetbrains.kotlin.android") version "2.2.20" apply false
}

include(":app")
