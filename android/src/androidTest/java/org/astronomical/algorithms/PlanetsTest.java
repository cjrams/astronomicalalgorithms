package org.astronomical.algorithms;

import android.support.test.runner.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.*;

import java.util.Calendar;
import java.util.TimeZone;

@RunWith(AndroidJUnit4.class)
public class PlanetsTest {
    @Test
    public void marsTests() {
        TimeZone gmt = TimeZone.getTimeZone("GTM");
        Calendar calendar = Calendar.getInstance(gmt);
        calendar.set(2010, Calendar.NOVEMBER,15);
        Mars mars = new Mars(calendar,41.7859f, 2.1699f);

        Calendar riseCalendar = Calendar.getInstance(gmt);
        riseCalendar.set(2010, Calendar.NOVEMBER,15, 8, 26, 18);
        Calendar setCalendar = Calendar.getInstance(gmt);
        setCalendar.set(2010, Calendar.NOVEMBER,15, 17, 34, 4);
        Calendar transitCalendar = Calendar.getInstance(gmt);
        transitCalendar.set(2010, Calendar.NOVEMBER,15, 13, 0, 18);

        assertEquals(mars.getRise().getTimeInMillis(), riseCalendar.getTimeInMillis(), 1000);
        assertEquals(mars.getSet().getTimeInMillis(), setCalendar.getTimeInMillis(), 1000);
        assertEquals(mars.getTransit().getTimeInMillis(), transitCalendar.getTimeInMillis(), 1000);
    }
}

