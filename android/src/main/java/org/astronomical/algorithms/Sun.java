package org.astronomical.algorithms;

import android.util.Log;

import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

public class Sun {
    private final String TAG = "AstronomicalAlgorithms";
    public Sun(Calendar date, float longitude, float latitude) {
        TimeZone timeZone = TimeZone.getTimeZone("GTM");
        sunRise = Calendar.getInstance(timeZone);
        sunSet = Calendar.getInstance(timeZone);
        sunTransit = Calendar.getInstance(timeZone);
        Log.d(TAG, "Date: " + date.toString());
        Log.d(TAG, "InitialSunRise: " + getSunRise().toString());
        CalcSunPosition(date, longitude ,latitude);
        Log.d(TAG, "SunRise: " + getSunRise().toString());
        Log.d(TAG, "SunTransit: " + getSunTransit().toString());
        Log.d(TAG, "SunSet: " + getSunSet().toString());
    }

    public Date getSunRise(){
        return sunRise.getTime();
    }

    public Date getSunSet(){
        return sunSet.getTime();
    }

    public Date getSunTransit(){
        return sunTransit.getTime();
    }

    private Calendar sunRise, sunSet, sunTransit;
    private native void CalcSunPosition(Calendar date, float longitude, float latitude);

    static {
        System.loadLibrary("astronomicalAlgorithms");
    }

}
