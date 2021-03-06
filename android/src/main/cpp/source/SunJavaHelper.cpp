#include <SunJavaHelper.h>
#include <DateConversions.h>

namespace JavaUtils {

SunJavaHelper::SunJavaHelper(JNIEnv* env)
	: AstronomicalBodyJavaHelper(env, env->FindClass("org/astronomical/algorithms/Sun")) {
	InitFields();
}

SunJavaHelper::~SunJavaHelper() {
	mEnv->DeleteLocalRef(mCls);
}

} //namespace JavaUtils
