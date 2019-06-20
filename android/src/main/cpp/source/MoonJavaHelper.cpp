#include <MoonJavaHelper.h>
#include <DateConversions.h>

namespace JavaUtils {

MoonJavaHelper::MoonJavaHelper(JNIEnv* env)
	: AstronomicalBodyJavaHelper(env, env->FindClass("org/astronomical/algorithms/Moon")) {
	InitFields();
}

MoonJavaHelper::~MoonJavaHelper() {
	mEnv->DeleteLocalRef(mCls);
}

} //namespace JavaUtils
