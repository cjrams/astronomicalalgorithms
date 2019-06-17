#pragma once
#include <jni.h>

namespace JavaUtils {
	class MoonJavaHelper {
		public:
			MoonJavaHelper(JNIEnv* env);
			~MoonJavaHelper();
			jobject GetMoonRise(jobject sun) const;
			jobject GetMoonSet(jobject sun) const;
			jobject GetMoonTransit(jobject sun) const;
		private:
			JNIEnv* mEnv;
			jclass mCls;
			jclass mClsClazz;
			jfieldID mMoonRiseFieldId;
			jfieldID mMoonSetFieldId;
			jfieldID mMoonTransitFieldId;
	};
}
