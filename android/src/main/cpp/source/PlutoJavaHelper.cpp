#include <PlutoJavaHelper.h>
#include <DateConversions.h>

namespace JavaUtils {

PlutoJavaHelper::PlutoJavaHelper(JNIEnv* env)
	: PlanetJavaHelper(env, env->FindClass("org/astronomical/algorithms/Mars")) {
	InitFields();
}

PlutoJavaHelper::~PlutoJavaHelper() {
	mEnv->DeleteLocalRef(mCls);
}

} //namespace JavaUtils
