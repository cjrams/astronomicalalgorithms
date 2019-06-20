#pragma once
#include <jni.h>

namespace JavaUtils {
	class AstronomicalBodyJavaHelper {
		public:
			AstronomicalBodyJavaHelper(JNIEnv* envmm, jclass cls);
			jobject GetRise(jobject object) const;
			jobject GetSet(jobject object) const;
			jobject GetTransit(jobject object) const;
		protected:
			void InitFields();
			JNIEnv* mEnv;
			jclass mCls;
			jfieldID mRiseFieldId;
			jfieldID mSetFieldId;
			jfieldID mTransitFieldId;
	};
}
