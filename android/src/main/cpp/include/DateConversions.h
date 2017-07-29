#pragma once
#include <jni.h>

class CAADate;

namespace JavaUtils {
	class DateConversions {
		public:
			DateConversions(JNIEnv* env);
			~DateConversions();
			CAADate Convert(jobject date) const;
			void Convert(CAADate date, jobject javaDate) const;
		private:
			JNIEnv* mEnv;
			jclass mCls;
			jmethodID mGetMethod;
			jmethodID mSetMethod;
			int mYearFieldId;
			int mMonthFieldId;
			int mDayFieldId;
	};
}
