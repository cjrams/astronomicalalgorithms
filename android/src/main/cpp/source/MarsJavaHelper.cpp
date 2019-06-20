#include <MarsJavaHelper.h>
#include <DateConversions.h>

namespace JavaUtils {

MarsJavaHelper::MarsJavaHelper(JNIEnv* env)
	: PlanetJavaHelper(env, env->FindClass("org/astronomical/algorithms/Mars")) {
	InitFields();
}

MarsJavaHelper::~MarsJavaHelper() {
	mEnv->DeleteLocalRef(mCls);
}

} //namespace JavaUtils
