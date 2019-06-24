package org.astronomical.algorithms.sample;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import org.astronomical.algorithms.Sun;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Calendar date = Calendar.getInstance();
        date.set(2017, 6, 15, 12, 0, 0);
        Sun sun = new Sun(date, (float)59.3293, (float)18.0686);
        DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
        Log.d("Test", "sun rise: " + dateFormat.format(sun.getSunRise().getTimeInMillis()));
        TextView sunRiseText = findViewById(R.id.sunRise);
        sunRiseText.setText("Sun rise: " + dateFormat.format(sun.getSunRise().getTimeInMillis()));
    }

}
