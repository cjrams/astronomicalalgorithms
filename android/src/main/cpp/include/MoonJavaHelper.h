#pragma once
#include <jni.h>

namespace JavaUtils {
	class MoonJavaHelper {
		public:
			MoonJavaHelper(JNIEnv* env);
			~MoonJavaHelper();
			jobject GetRise(jobject sun) const;
			jobject GetSet(jobject sun) const;
			jobject GetTransit(jobject sun) const;
		private:
			JNIEnv* mEnv;
			jclass mCls;
			jfieldID mRiseFieldId;
			jfieldID mSetFieldId;
			jfieldID mTransitFieldId;
	};
}
