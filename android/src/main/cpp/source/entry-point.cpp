#include <jni.h>
#include <android/log.h>
#include <DateConversions.h>
#include <SunJavaHelper.h>
#include <MoonJavaHelper.h>
#include <aawrapper/Sun.h>
#include <aawrapper/Moon.h>
#include <aaplus/AADate.h>

namespace{
	constexpr const char* Tag = "AstronomicalAlgorithms";
}

extern "C" jint JNI_OnLoad(JavaVM* vm, void* /*reserved*/)
{
	JNIEnv* env;
	if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
		return -1;
	}

	// Get jclass with env->FindClass.
	// Register methods with env->RegisterNatives.

	return JNI_VERSION_1_6;
}

extern "C" JNIEXPORT void JNICALL
Java_org_astronomical_algorithms_Sun_CalcSunPosition(JNIEnv *env, jclass javaSun, jobject date,
		jfloat longitude, jfloat latitude) {

	JavaUtils::DateConversions dateConversions(env);
	JavaUtils::SunJavaHelper sunJavaHelper(env);
	auto sunDate = dateConversions.Convert(date);
	AstronomicalAlgorithms::Sun sun (sunDate, latitude, longitude);

	auto rise = sun.GetRise();
	auto set = sun.GetSet();
	auto transit = sun.GetTransit();
	dateConversions.Convert(rise, sunJavaHelper.GetSunRise(javaSun));
	dateConversions.Convert(set, sunJavaHelper.GetSunSet(javaSun));
	dateConversions.Convert(transit, sunJavaHelper.GetSunTransit(javaSun));

	//Debug logs
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcSunPosition Date %ld-%ld-%ld %ld:%ld:%f", sunDate.Year(), sunDate.Month(), sunDate.Day(), sunDate.Hour(), sunDate.Minute(), sunDate.Second());
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcSunPosition longitude: %f latitude: %f", longitude, latitude);
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcSunPosition Rise %ld-%ld-%ld %ld:%ld:%f", rise.Year(), rise.Month(), rise.Day(), rise.Hour(), rise.Minute(), rise.Second());
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcSunPosition Transit %ld-%ld-%ld %ld:%ld:%f", transit.Year(), transit.Month(), transit.Day(), transit.Hour(), transit.Minute(), transit.Second());
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcSunPosition Set %ld-%ld-%ld %ld:%ld:%f", set.Year(), set.Month(), set.Day(), set.Hour(), set.Minute(), set.Second());
}

extern "C" JNIEXPORT void JNICALL
Java_org_astronomical_algorithms_Moon_CalcMoonPosition(JNIEnv *env, jclass javaMoon, jobject date,
		jfloat longitude, jfloat latitude) {

	JavaUtils::DateConversions dateConversions(env);
    	JavaUtils::MoonJavaHelper moonJavaHelper(env);
	auto moonDate = dateConversions.Convert(date);
	AstronomicalAlgorithms::Moon moon (moonDate, latitude, longitude);

	auto rise = moon.GetRise();
	auto set = moon.GetSet();
	auto transit = moon.GetTransit();
	dateConversions.Convert(rise, moonJavaHelper.GetMoonRise(javaMoon));
	dateConversions.Convert(set, moonJavaHelper.GetMoonSet(javaMoon));
	dateConversions.Convert(transit, moonJavaHelper.GetMoonTransit(javaMoon));

	//Debug logs
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcMoonPosition Date %ld-%ld-%ld %ld:%ld:%f", moonDate.Year(), moonDate.Month(), moonDate.Day(), moonDate.Hour(), moonDate.Minute(), moonDate.Second());
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcMoonPosition longitude: %f latitude: %f", longitude, latitude);
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcMonnPosition Rise %ld-%ld-%ld %ld:%ld:%f", rise.Year(), rise.Month(), rise.Day(), rise.Hour(), rise.Minute(), rise.Second());
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcMonnPosition Transit %ld-%ld-%ld %ld:%ld:%f", transit.Year(), transit.Month(), transit.Day(), transit.Hour(), transit.Minute(), transit.Second());
	__android_log_print(ANDROID_LOG_DEBUG, Tag, "CalcMonnPosition Set %ld-%ld-%ld %ld:%ld:%f", set.Year(), set.Month(), set.Day(), set.Hour(), set.Minute(), set.Second());
}
