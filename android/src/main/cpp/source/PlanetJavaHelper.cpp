#include <PlanetJavaHelper.h>
#include <DateConversions.h>

namespace JavaUtils {

PlanetJavaHelper::PlanetJavaHelper(JNIEnv* env)
	: mEnv(env) {}

void PlanetJavaHelper::InitFields() {
	mRiseFieldId = mEnv->GetFieldID(mCls, "rise", "Ljava/util/Calendar;");
	mSetFieldId = mEnv->GetFieldID(mCls, "set", "Ljava/util/Calendar;");
	mTransitFieldId = mEnv->GetFieldID(mCls, "transit", "Ljava/util/Calendar;");
}

jobject PlanetJavaHelper::GetRise(jobject object) const {
	return mEnv->GetObjectField(object, mRiseFieldId);
}

jobject PlanetJavaHelper::GetSet(jobject object) const {
	return mEnv->GetObjectField(object, mSetFieldId);
}

jobject PlanetJavaHelper::GetTransit(jobject object) const {
	return mEnv->GetObjectField(object, mTransitFieldId);
}

} //namespace JavaUtils
