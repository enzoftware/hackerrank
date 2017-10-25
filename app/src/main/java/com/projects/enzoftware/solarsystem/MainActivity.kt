package com.projects.enzoftware.solarsystem

import android.animation.ValueAnimator
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.constraint.ConstraintLayout
import android.support.constraint.ConstraintSet
import android.view.animation.LinearInterpolator
import android.widget.ImageView
import kotlinx.android.synthetic.main.activity_main.*
import java.util.concurrent.TimeUnit

class MainActivity : AppCompatActivity() {

    val orbitsConstraint : ConstraintSet = ConstraintSet()
    val detailsConstraint : ConstraintSet = ConstraintSet()

    override fun onCreate(savedInstanceState: Bundle?) {

        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        //orbitsConstraint.clone(rut)
        //detailsConstraint.clone(this,R.layout.detail_activity)

        val earthAnimate: ValueAnimator = animatePlanet(earth,TimeUnit.SECONDS.toMillis(2))
        val marsAnimate : ValueAnimator = animatePlanet(mars,TimeUnit.SECONDS.toMillis(6))
        val saturnAnimate : ValueAnimator = animatePlanet(saturn,TimeUnit.SECONDS.toMillis(12))

        earthAnimate.start()
        marsAnimate.start()
        saturnAnimate.start()

        sun.setOnClickListener {
            //earthAnimate.cancel()
            //marsAnimate.cancel()
            //saturnAnimate.cancel()
            // TransitionManager.beginDelayedTransition(root)
            // detailsConstraint.applyTo(root)

            /**
             * Help meeeee :'v
             **/
        }


    }

    fun animatePlanet(planet: ImageView, orbitDuration: Long): ValueAnimator {
        val anim: ValueAnimator = ValueAnimator.ofInt(0, 359)
        anim.addUpdateListener {
            animation: ValueAnimator? ->
            run {

                val valueAngle: Int = animation!!.animatedValue as Int
                val layoutParams: ConstraintLayout.LayoutParams = planet.layoutParams as ConstraintLayout.LayoutParams
                layoutParams.circleAngle = valueAngle.toFloat()
                planet.layoutParams = layoutParams

            }
        }

        anim.duration = orbitDuration
        anim.interpolator = LinearInterpolator()
        anim.repeatMode = ValueAnimator.RESTART
        anim.repeatCount = ValueAnimator.INFINITE

        return anim
    }
}
