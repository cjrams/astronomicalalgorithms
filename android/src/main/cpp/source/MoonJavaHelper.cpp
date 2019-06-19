#include <MoonJavaHelper.h>
#include <DateConversions.h>

namespace JavaUtils {

MoonJavaHelper::MoonJavaHelper(JNIEnv* env)
	: mEnv(env)
{
	mCls = env->FindClass("org/astronomical/algorithms/Moon");
	mRiseFieldId = mEnv->GetFieldID(mCls, "rise", "Ljava/util/Calendar;");
	mSetFieldId = mEnv->GetFieldID(mCls, "set", "Ljava/util/Calendar;");
	mTransitFieldId = mEnv->GetFieldID(mCls, "transit", "Ljava/util/Calendar;");
}

MoonJavaHelper::~MoonJavaHelper() {
	mEnv->DeleteLocalRef(mCls);
}

jobject MoonJavaHelper::GetRise(jobject object) const {
	return mEnv->GetObjectField(object, mRiseFieldId);
}

jobject MoonJavaHelper::GetSet(jobject object) const {
	return mEnv->GetObjectField(object, mSetFieldId);
}

jobject MoonJavaHelper::GetTransit(jobject object) const {
	return mEnv->GetObjectField(object, mTransitFieldId);
}

} //namespace JavaUtils
