# Astronomical Algorithms
Export aaplus as library for mobile development. Initially for Android

## How to use it
Add this line into your build.gradle inside dependencies
`implementation 'org.cjrams:astronomical-algorithms:0.4.0'`

The you can use the MPV version to get sun rise, set and transition for any date and location

```
Calendar calendar = Calendar.getInstance();
calendar.set(2017, 6, 15, 12, 0, 0);
Sun sun = new Sun(calendar, (float)59.3293, (float)18.0686);
DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
Log.d("Test", "sun rise: " + dateFormat.format(sun.getRise().getTimeInMillis()));
```

## Using flavors

In order to reduce the resulting versions, the recommendation is to use product flavors. Libray is release with all actual abi binaries. But the recommendation is to use only one for distribution apk. Also if your application don't need to build specifics for any abi, while main ones are compatible, use only arm-v7a or also add x86.
Here is a snipped to add to the build.gradle application file to make smaller packages that follows the previous comments.

```
productFlavors {
    arm7 {
        dimension "abi"
        ndk {
            abiFilters  "armeabi-v7a"
        }
    }
    x86 {
        dimension "abi"
        ndk {
            abiFilters "x86"
        }
    }
    fat {
        dimension "abi"
        ndk {
            abiFilters "x86", "armeabi-v7a"
        }
    }
}
```
