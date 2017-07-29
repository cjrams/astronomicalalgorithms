package org.astronomical.algorithms;

import android.util.Log;

import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;

public class Sun {
    public Sun(Calendar date, float longitude, float latitude) {
        TimeZone timeZone = TimeZone.getTimeZone("GTM");
        sunRise = Calendar.getInstance(timeZone);
        sunSet = Calendar.getInstance(timeZone);
        sunTransit = Calendar.getInstance(timeZone);
        Log.d("AstronomicalAlgorithms", "Date: " + date.toString());
        Log.d("AstronomicalAlgorithms", "InitialSunRise: " + getSunRise().toString());
        CalcSunPosition(date, longitude ,latitude);
        Log.d("AstronomicalAlgorithms", "SunRise: " +getSunRise().toString());
        Log.d("AstronomicalAlgorithms", "SunTransit: " +getSunTransit().toString());
        Log.d("AstronomicalAlgorithms", "SunSet: " +getSunSet().toString());
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
