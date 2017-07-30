# Astronomical Algorithms
Export aaplus as library for mobile development. Initially for Android

## How to use it
Add this line into your build.gradle inside dependencies
`compile 'org.cjrams:astronomical-algorithms:0.1.0'`

The you can use the MPV version to get sun rise, set and transition for any date and location
```
Calendar date = Calendar.getInstance();
date.set(2017, 6, 15, 12, 0, 0);
Sun sun = new Sun(date, (float)59.3293, (float)18.0686);
sun.getSunRise();
Date sunRise = sun.getSunRise();
Log.d("Test", "sun rise: " + sunRise.toString());
```
