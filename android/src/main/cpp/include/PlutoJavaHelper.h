#pragma once
#include <jni.h>
#include <PlanetJavaHelper.h>

namespace JavaUtils {
	class PlutoJavaHelper : public PlanetJavaHelper {
		public:
			PlutoJavaHelper(JNIEnv* env);
			~PlutoJavaHelper();
	};
}
