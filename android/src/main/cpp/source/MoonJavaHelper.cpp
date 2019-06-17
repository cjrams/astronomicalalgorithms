#include <MoonJavaHelper.h>
#include <DateConversions.h>

namespace JavaUtils {

MoonJavaHelper::MoonJavaHelper(JNIEnv* env)
	: mEnv(env)
{
	mCls = env->FindClass("org/astronomical/algorithms/Moon");
	mMoonRiseFieldId = mEnv->GetFieldID(mCls, "moonRise", "Ljava/util/Calendar;");
	mMoonSetFieldId = mEnv->GetFieldID(mCls, "moonSet", "Ljava/util/Calendar;");
	mMoonTransitFieldId = mEnv->GetFieldID(mCls, "moonTransit", "Ljava/util/Calendar;");
}

MoonJavaHelper::~MoonJavaHelper() {
	mEnv->DeleteLocalRef(mCls);
}

jobject MoonJavaHelper::GetMoonRise(jobject noom) const {
	return mEnv->GetObjectField(noom, mMoonRiseFieldId);
}

jobject MoonJavaHelper::GetMoonSet(jobject noom) const {
	return mEnv->GetObjectField(noom, mMoonSetFieldId);
}

jobject MoonJavaHelper::GetMoonTransit(jobject noom) const {
	return mEnv->GetObjectField(noom, mMoonTransitFieldId);
}

} //namespace JavaUtils
