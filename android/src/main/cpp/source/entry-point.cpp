#include <jni.h>
#include <android/log.h>
#include <DateConversions.h>
#include <SunJavaHelper.h>
#include <MoonJavaHelper.h>
#include <MarsJavaHelper.h>
#include <aawrapper/Sun.h>
#include <aawrapper/Moon.h>
#include <aawrapper/Mars.h>
#include <aaplus/AADate.h>
#include <memory>

struct JavaHelpers {
    std::unique_ptr<JavaUtils::DateConversions> dateConversions;
    std::unique_ptr<JavaUtils::SunJavaHelper> sun;
    std::unique_ptr<JavaUtils::MoonJavaHelper> moon;
	std::unique_ptr<JavaUtils::MarsJavaHelper> mars;
};

namespace {
    JavaHelpers javaHelpers;
} //namespace

extern "C" jint JNI_OnLoad(JavaVM* vm, void* /*reserved*/){
	JNIEnv* env;
	if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
		return -1;
	}

	javaHelpers.dateConversions = std::make_unique<JavaUtils::DateConversions>(env);
	javaHelpers.sun = std::make_unique<JavaUtils::SunJavaHelper>(env);
	javaHelpers.moon = std::make_unique<JavaUtils::MoonJavaHelper>(env);
	javaHelpers.mars = std::make_unique<JavaUtils::MarsJavaHelper>(env);

	return JNI_VERSION_1_6;
}

extern "C" void JNI_OnUnload(JavaVM* vm, void* /*reserved*/) {
	javaHelpers.dateConversions.reset();
	javaHelpers.sun.reset();
	javaHelpers.moon.reset();
	javaHelpers.mars.reset();
}

extern "C" JNIEXPORT void JNICALL
Java_org_astronomical_algorithms_Sun_CalcPosition(JNIEnv* /*env*/, jclass javaSun, jobject date,
		jfloat longitude, jfloat latitude) {
	auto sunDate = javaHelpers.dateConversions->Convert(date);
	AstronomicalAlgorithms::Sun sun(sunDate, latitude, longitude);

	javaHelpers.dateConversions->Convert(sun.GetRise(), javaHelpers.sun->GetRise(javaSun));
	javaHelpers.dateConversions->Convert(sun.GetSet(), javaHelpers.sun->GetSet(javaSun));
	javaHelpers.dateConversions->Convert(sun.GetTransit(), javaHelpers.sun->GetTransit(javaSun));
}

extern "C" JNIEXPORT void JNICALL
Java_org_astronomical_algorithms_Moon_CalcPosition(JNIEnv* /*env*/, jclass javaMoon, jobject date,
		jfloat longitude, jfloat latitude) {
	auto moonDate = javaHelpers.dateConversions->Convert(date);
	AstronomicalAlgorithms::Moon moon(moonDate, latitude, longitude);

	javaHelpers.dateConversions->Convert(moon.GetRise(), javaHelpers.moon->GetRise(javaMoon));
	javaHelpers.dateConversions->Convert(moon.GetSet(), javaHelpers.moon->GetSet(javaMoon));
	javaHelpers.dateConversions->Convert(moon.GetTransit(), javaHelpers.moon->GetTransit(javaMoon));
}

extern "C" JNIEXPORT void JNICALL
Java_org_astronomical_algorithms_Mars_CalcPosition(JNIEnv* /*env*/, jclass javaMars, jobject date,
												   jfloat longitude, jfloat latitude) {
	auto marsDate = javaHelpers.dateConversions->Convert(date);
    	AstronomicalAlgorithms::Mars mars(marsDate, latitude, longitude);

	javaHelpers.dateConversions->Convert(mars.GetRise(), javaHelpers.mars->GetRise(javaMars));
	javaHelpers.dateConversions->Convert(mars.GetSet(), javaHelpers.mars->GetSet(javaMars));
	javaHelpers.dateConversions->Convert(mars.GetTransit(), javaHelpers.mars->GetTransit(javaMars));
}
