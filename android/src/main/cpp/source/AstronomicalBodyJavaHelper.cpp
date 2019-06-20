#include <AstronomicalBodyJavaHelper.h>
#include <DateConversions.h>

namespace JavaUtils {

AstronomicalBodyJavaHelper::AstronomicalBodyJavaHelper(JNIEnv* env, jclass cls)
	: mEnv(env)
	, mCls(cls) {}

void AstronomicalBodyJavaHelper::InitFields() {
	mRiseFieldId = mEnv->GetFieldID(mCls, "rise", "Ljava/util/Calendar;");
	mSetFieldId = mEnv->GetFieldID(mCls, "set", "Ljava/util/Calendar;");
	mTransitFieldId = mEnv->GetFieldID(mCls, "transit", "Ljava/util/Calendar;");
}

jobject AstronomicalBodyJavaHelper::GetRise(jobject object) const {
	return mEnv->GetObjectField(object, mRiseFieldId);
}

jobject AstronomicalBodyJavaHelper::GetSet(jobject object) const {
	return mEnv->GetObjectField(object, mSetFieldId);
}

jobject AstronomicalBodyJavaHelper::GetTransit(jobject object) const {
	return mEnv->GetObjectField(object, mTransitFieldId);
}

} //namespace JavaUtils
