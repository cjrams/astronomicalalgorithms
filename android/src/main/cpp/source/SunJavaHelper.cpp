#include <SunJavaHelper.h>
#include <DateConversions.h>

namespace JavaUtils {

SunJavaHelper::SunJavaHelper(JNIEnv* env)
	: mEnv(env)
{
	mCls = env->FindClass("org/astronomical/algorithms/Sun");
	mSunRiseFieldId = mEnv->GetFieldID(mCls, "sunRise", "Ljava/util/Calendar;");
	mSunSetFieldId = mEnv->GetFieldID(mCls, "sunSet", "Ljava/util/Calendar;");
	mSunTransitFieldId = mEnv->GetFieldID(mCls, "sunTransit", "Ljava/util/Calendar;");
}

SunJavaHelper::~SunJavaHelper() {
	mEnv->DeleteLocalRef(mCls);
}

jobject SunJavaHelper::GetSunRise(jobject sun) const {
	return mEnv->GetObjectField(sun, mSunRiseFieldId);
}

jobject SunJavaHelper::GetSunSet(jobject sun) const {
	return mEnv->GetObjectField(sun, mSunSetFieldId);
}

jobject SunJavaHelper::GetSunTransit(jobject sun) const {
	return mEnv->GetObjectField(sun, mSunTransitFieldId);
}

} //namespace JavaUtils
