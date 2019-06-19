#pragma once
#include <jni.h>
#include <PlanetJavaHelper.h>

namespace JavaUtils {
	class MarsJavaHelper : public PlanetJavaHelper {
		public:
			MarsJavaHelper(JNIEnv* env);
			~MarsJavaHelper();
	};
}
