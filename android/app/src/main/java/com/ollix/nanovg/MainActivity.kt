/*
 * Copyright (c) 2017 Olli Wang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * ---
 * Author: olliwang@ollix.com (Olli Wang)
 */

package com.ollix.nanovg

import android.app.Activity
import android.content.res.AssetManager
import android.os.Bundle
import android.view.View
import android.widget.RelativeLayout

import androidx.fragment.app.FragmentActivity

import com.ollix.moui.MouiFragment

class MainActivity : FragmentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        /** Creates the root view. */
        val rootView = RelativeLayout(this)
        rootView.id = View.generateViewId()
        setContentView(rootView)

        /** Initializes the moui app. */
        inithMouiAppFromJNI(this, assets)

        /** Adds moui fragment to show the UI of the moui app. */
        val fragmentTransaction = supportFragmentManager.beginTransaction()
        fragmentTransaction.add(rootView.id, MouiFragment())
        fragmentTransaction.commit()
    }

    override fun onDestroy() {
        deleteApplicationFromJNI()
    }

    /** JNI methods. */
    external fun inithMouiAppFromJNI(activity: Activity,
                                     assetManager: AssetManager)
    external fun deleteApplicationFromJNI()

    /** Loads native libraries. */
    companion object {
        init {
            System.loadLibrary("app-jni")
        }
    }
}
