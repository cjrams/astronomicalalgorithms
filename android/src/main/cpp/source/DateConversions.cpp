#include <DateConversions.h>
#include <aaplus/AADate.h>

namespace JavaUtils {

DateConversions::DateConversions(JNIEnv* env)
	: mEnv(env)
{
	mCls = env->FindClass("java/util/Calendar");
	mGetMethod = mEnv->GetMethodID(mCls, "get", "(I)I");
	mSetMethod = mEnv->GetMethodID(mCls, "set", "(IIIIII)V");
	mYearFieldId = mEnv->GetStaticIntField(mCls, mEnv->GetStaticFieldID(mCls, "YEAR", "I"));
	mMonthFieldId = mEnv->GetStaticIntField(mCls, mEnv->GetStaticFieldID(mCls, "MONTH", "I"));
	mDayFieldId = mEnv->GetStaticIntField(mCls, mEnv->GetStaticFieldID(mCls, "DAY_OF_MONTH", "I"));
}

DateConversions::~DateConversions() {
	mEnv->DeleteLocalRef(mCls);
}

CAADate DateConversions::Convert(jobject date) const {
	return CAADate(
		mEnv->CallIntMethod(date, mGetMethod, mYearFieldId),
		mEnv->CallIntMethod(date, mGetMethod, mMonthFieldId) + 1,
		mEnv->CallIntMethod(date, mGetMethod, mDayFieldId),
		true);
}

void DateConversions::Convert(CAADate date, jobject javaDate) const {
	mEnv->CallVoidMethod(
		javaDate,
		mSetMethod,
		date.Year(),
		date.Month() - 1,
		date.Day(),
		date.Hour(),
		date.Minute(),
		static_cast<int>(date.Second()));
}

} //namespace JavaUtils
