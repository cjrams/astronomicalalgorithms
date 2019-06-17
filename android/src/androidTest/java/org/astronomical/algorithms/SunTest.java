package org.astronomical.algorithms;

import android.support.test.runner.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.*;

import java.util.Calendar;
import java.util.TimeZone;

@RunWith(AndroidJUnit4.class)
public class SunTest {
    @Test
    public void sunTests() {
        TimeZone gmt = TimeZone.getTimeZone("GTM");
        Calendar sunCalendar = Calendar.getInstance(gmt);
        sunCalendar.set(2010, Calendar.NOVEMBER,15);
        Sun sun = new Sun(sunCalendar,41.7859f, 2.1699f);

        Calendar sunRiseCalendar = Calendar.getInstance(gmt);
        sunRiseCalendar.set(2010, Calendar.NOVEMBER,15, 6, 40, 24);
        Calendar sunSetCalendar = Calendar.getInstance(gmt);
        sunSetCalendar.set(2010, Calendar.NOVEMBER,15, 16, 30, 58);
        Calendar sunTransitCalendar = Calendar.getInstance(gmt);
        sunTransitCalendar.set(2010, Calendar.NOVEMBER,15, 11, 35, 54);

        assertEquals(sun.getSunRise().getTimeInMillis(), sunRiseCalendar.getTimeInMillis(), 1000);
        assertEquals(sun.getSunSet().getTimeInMillis(), sunSetCalendar.getTimeInMillis(), 1000);
        assertEquals(sun.getSunTransit().getTimeInMillis(), sunTransitCalendar.getTimeInMillis(), 1000);
    }
}

