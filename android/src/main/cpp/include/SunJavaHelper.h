#pragma once
#include <jni.h>

namespace JavaUtils {
	class SunJavaHelper {
		public:
			SunJavaHelper(JNIEnv* env);
			~SunJavaHelper();
			jobject GetSunRise(jobject sun) const;
			jobject GetSunSet(jobject sun) const;
			jobject GetSunTransit(jobject sun) const;
		private:
			JNIEnv* mEnv;
			jclass mCls;
			jclass mClsClazz;
			jfieldID mSunRiseFieldId;
			jfieldID mSunSetFieldId;
			jfieldID mSunTransitFieldId;
	};
}
