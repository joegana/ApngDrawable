package com.moorgen.panel13


object Versions {

    const val jfrog_version = "4.15.1"
    const val buildGradle = "7.0.2"

    const val retrofit = "2.9.0"

    const val kotlin = "1.6.21"
    const val kotlinx = "1.6.0"
    const val bintrayRelease = "0.9.1"

    const val appcompat = "1.2.0"
    const val coreKtx = "1.3.2"
    const val material = "1.2.1"
    const val constraintlayout = "2.0.4"
    const val extensions = "2.2.0"
    const val room = "2.3.0"
    const val lifecycle = "2.3.1"
    const val workManager = "2.3.1"
    const val fragment = "1.2.4"
    const val activity = "1.2.4"
    const val legacy = "1.0.0"
    const val cardView = "1.0.0"
    const val gridLayout = "1.0.0"
    const val multidex = "2.0.0"
    const val emoji ="1.1.0"
    const val percentLayout = "1.0.0"

    const val junit = "4.12"
    const val junitExt = "1.1.2"
    const val espressoCore = "3.3.0"

    const val banner = "2.2.2"
    const val BRVAH = "3.0.4"
    const val ultimateBarX = "0.7.1"
    const val coil = "1.4.0"
    const val materialDialogs = "3.1.1"
    const val utilCode = "1.30.6"
    const val bottomTab = "2.3.0X"
    const val bdclta = "3.1.1"
    const val swiperefresh = "1.1.0"

    const val okhttp = "4.9.2"
    const val okio = "1.13.0"
    const val mmkv = "1.2.11"
    const val xxpermission = "13.6"
    const val logger = "2.2.0"
    const val mgLogger = "1.3.7"

    const val mqttCore = "1.2.5"
    const val mqttAndroid = "1.1.4"

    const val glide = "4.12.0"

    const val vertx = "3.9.10"

    const val skin_frame_version = "4.0.6.2"

    const val sdkCommon = "1.5.6.8"
    const val shcp = "5.6.4_2023_05_12_2_SNAPSHOT"
    const val bgm = "5.5.4_2023_03_24_1_SNAPSHOT"

    const val smartRefresh = "2.0.3"

    const val exoplayer = "2.15.1"

    const val arouter = "1.5.2"
    const val arouterReg = "1.0.2"
    const val android_apt = "1.8"
}

object AndroidX {

    const val appcompat = "androidx.appcompat:appcompat:${Versions.appcompat}"
    const val legacy_support =  "androidx.legacy:legacy-support-v4:1.0.0"
    const val coreKtx = "androidx.core:core-ktx:${Versions.coreKtx}"
    const val constraintlayout =
        "androidx.constraintlayout:constraintlayout:${Versions.constraintlayout}"
    const val material = "com.google.android.material:material:${Versions.material}"
    const val lifecycleExtensions = "androidx.lifecycle:lifecycle-extensions:${Versions.extensions}"
    const val lifecycleViewmodelKtx =
        "androidx.lifecycle:lifecycle-viewmodel-ktx:${Versions.lifecycle}"
    const val lifecycleLiveDataKtx = "androidx.lifecycle:lifecycle-livedata-ktx:${Versions.lifecycle}"
    const val lifeCycleRuntime = "androidx.lifecycle:lifecycle-runtime-ktx:${Versions.lifecycle}"

    //    helpers for implementing LifecycleOwner in a Service
    const val lifecycle_service = "androidx.lifecycle:lifecycle-service:${Versions.lifecycle}"
    //    Annotation processor
    const val lifecycle_compiler = "androidx.lifecycle:lifecycle-compiler:${Versions.lifecycle}"
    //    ProcessLifecycleOwner provides a lifecycle for the whole application process
    const val lifecycle_process = "androidx.lifecycle:lifecycle-process:${Versions.lifecycle}"
    //ReactiveStreams support for LiveData
    const val lifecycle_reactivestreams_ktx = "androidx.lifecycle:lifecycle-reactivestreams-ktx:${Versions.lifecycle}"

    const val fragment = "androidx.fragment:fragment-ktx:${Versions.fragment}"
    const val activity = "androidx.activity:activity-ktx:${Versions.activity}"

    const val legacy = "androidx.legacy:legacy-support-v4:${Versions.legacy}"
    const val cardView = "androidx.cardview:cardview:${Versions.cardView}"
    const val gridLayout = "androidx.gridlayout:gridlayout:${Versions.gridLayout}"
    const val multidex = "androidx.multidex:multidex:${Versions.multidex}"
    //百分比布局依赖
    const val percentLayout = "androidx.percentlayout:percentlayout:${Versions.percentLayout}"

    const val security_crypto = "androidx.security:security-crypto:1.1.0-alpha03"


    const val multidex_instrumentation = "androidx.multidex:multidex-instrumentation:2.0.0"

    val emoji = arrayOf(
        "androidx.emoji:emoji:${Versions.emoji}",
        "androidx.emoji:emoji-bundled:${Versions.emoji}"
    )

    const val workerManager = "androidx.work:work-runtime-ktx:${Versions.workManager}"

    val values = arrayListOf(
        appcompat,
        coreKtx,
        constraintlayout,
        material,
        lifecycleExtensions,
        lifecycleViewmodelKtx,
        lifecycleLiveDataKtx,
        lifecycle_process,
        lifeCycleRuntime,
        legacy_support,
        activity,
        fragment,
        percentLayout,
        legacy,
        cardView,
        gridLayout,
        multidex,
        *emoji,
        workerManager
    )

    val sdkValues = arrayListOf(
            appcompat,
            lifecycleLiveDataKtx,
            lifecycle_process,
            workerManager
        )
}

object Mqtt{
    const val mqttv3 = "org.eclipse.paho:org.eclipse.paho.client.mqttv3:${Versions.mqttCore}"
    const val mqttv3Android = "org.eclipse.paho:org.eclipse.paho.android.service:${Versions.mqttAndroid}"
    var values = arrayListOf(
        mqttv3,
        mqttv3Android
    )
}


object Kt {
    const val stdlibJdk7 = "org.jetbrains.kotlin:kotlin-stdlib-jdk7:${Versions.kotlin}"
    const val stdlibJdk8 = "org.jetbrains.kotlin:kotlin-stdlib-jdk8:${Versions.kotlin}"
    const val test = "org.jetbrains.kotlin:kotlin-test-junit:${Versions.kotlin}"
    const val plugin = "org.jetbrains.kotlin:kotlin-gradle-plugin:${Versions.kotlin}"
    const val coroutine =  "org.jetbrains.kotlinx:kotlinx-coroutines-android:${Versions.kotlinx}"
    const val coroutineTest =  "org.jetbrains.kotlinx:kotlinx-coroutines-test:${Versions.kotlinx}"
    val values = arrayListOf(stdlibJdk8, coroutine)
    val testValues = arrayListOf(test, coroutineTest)
}

object Room {
    const val runtime = "androidx.room:room-runtime:${Versions.room}"
    const val compiler = "androidx.room:room-compiler:${Versions.room}"
    const val ktx = "androidx.room:room-ktx:${Versions.room}"
    const val testing = "androidx.room:room-testing:${Versions.room}"
}

object Retrofit {
    //Retrofit
    const val okHttp = "com.squareup.okhttp3:okhttp:${Versions.okhttp}"
    const val okHttpLogging =  "com.squareup.okhttp3:logging-interceptor:${Versions.okhttp}"
    const val okio =  "com.squareup.okio:okio:${Versions.okio}"
    const val runtime = "com.squareup.retrofit2:retrofit:${Versions.retrofit}"
    const val gson = "com.squareup.retrofit2:converter-gson:${Versions.retrofit}"
    const val adapter = "com.squareup.retrofit2:adapter-rxjava2:${Versions.retrofit}"
    val values = arrayListOf(okHttp,okHttpLogging,okio,runtime, gson)
}

object Vertx{
    const val vertx_core = "io.vertx:vertx-core:${Versions.vertx}"
    const val vertx_web_client = "io.vertx:vertx-web-client:${Versions.vertx}"
    const val vertx_mqtt = "io.vertx:vertx-mqtt:${Versions.vertx}"
    val values = arrayListOf(vertx_core,vertx_web_client,vertx_mqtt)
}

object SkinFrame{
    const val core = "android.skin:skin-support:${Versions.skin_frame_version}"
    const val appcompat = "android.skin:skin-support-appcompat:${Versions.skin_frame_version}"
    const val design = "android.skin:skin-support-design:${Versions.skin_frame_version}"
    const val cardview = "android.skin:skin-support-cardview:${Versions.skin_frame_version}"
    const val constraint_layout = "android.skin:skin-support-constraint-layout:${Versions.skin_frame_version}"
    val values = arrayListOf(
        core,appcompat,design,cardview,constraint_layout
    )
}


object Slf4Android{
    // slf4j
    const val slf4j_api  =  "org.slf4j:slf4j-api:2.0.3"
    const val slf4j_log4j = "org.slf4j:slf4j-log4j12:2.0.3"
    // log4j
    const val log4j_core =  "org.apache.logging.log4j:log4j-core:2.19.0"
    const val log4j_api =  "org.apache.logging.log4j:log4j-api:2.19.0"
    const val disrupter =  "com.lmax:disruptor:3.4.4"
    // log4android
    const val log4j_android =  "de.mindpipe.android:android-logging-log4j:1.0.3"

    var values = arrayListOf(log4j_core, log4j_api, disrupter, log4j_android,slf4j_api, slf4j_log4j)
}

object MoorgenControls{
    const val wheelview = "com.moorgen.controls:wheelview:1.5.4"
    const val curtain =  "com.moorgen.controls:curtain:2.2.3_2023_05_11_1_SNAPSHOT"
    const val superrecyclerview =  "com.moorgen.controls:superrecyclerview:2.0.9.6"
    //GridLayout 替换方案
    const val spannedgridlayoutmanager =  "io.github.joeiot:spannedgridlayoutmanager:4.0.0"
//    const val spannedgridlayoutmanager =  "com.joeiot:spannedgridlayoutmanager:4.0.0_2022_06_18_1_SNAPSHOT"
    var values = arrayListOf(
        wheelview, curtain, spannedgridlayoutmanager,superrecyclerview
    )
}

object Depend {
    const val junit = "junit:junit:${Versions.junit}"
    const val androidTestJunit = "androidx.test.ext:junit:${Versions.junitExt}"
    const val espressoCore = "androidx.test.espresso:espresso-core:${Versions.espressoCore}"
    const val banner = "io.github.youth5201314:banner:${Versions.banner}"
    const val BRVAH = "com.github.CymChad:BaseRecyclerViewAdapterHelper:${Versions.BRVAH}"
    const val ultimateBarX = "com.github.Zackratos:UltimateBarX:${Versions.ultimateBarX}"
    const val coil = "io.coil-kt:coil:${Versions.coil}" //图片加载
    const val dialogs = "com.afollestad.material-dialogs:lifecycle:${Versions.materialDialogs}"
    const val dialogsCore = "com.afollestad.material-dialogs:core:${Versions.materialDialogs}"
    const val utilCode = "com.blankj:utilcodex:${Versions.utilCode}"
    const val bottomTab = "me.majiajie:pager-bottom-tab-strip:${Versions.bottomTab}"
    const val bdclta =
        "me.tatarka.bindingcollectionadapter2:bindingcollectionadapter:${Versions.bdclta}"
    const val bdcltaRv =
        "me.tatarka.bindingcollectionadapter2:bindingcollectionadapter-recyclerview:${Versions.bdclta}"
    const val swiperefresh =
        "androidx.swiperefreshlayout:swiperefreshlayout:${Versions.swiperefresh}"

    const val mmkv = "com.tencent:mmkv:${Versions.mmkv}"

//    const val xxPermission = "com.github.getActivity:XXPermissions:${Versions.xxpermission}"
    // 本地文件日志Log
    const val logger = "com.orhanobut:logger:${Versions.logger}"
    const val mgCommon = "com.moorgen.sdk:common:${Versions.sdkCommon}"
    const val glide =   "com.github.bumptech.glide:glide:${Versions.glide}"
    // Moorgen SDK  在使用
    const val fastJson =  "com.alibaba:fastjson:1.1.70.android"
    // Moorgen Log
    const val mgLogger = "com.moorgen.smarthome:android-logger:${Versions.mgLogger}"

    const val pinyin4j =  "net.sourceforge:pinyin4j:2.0.0"

    const val popView = "io.github.razerdp:BasePopup:3.2.0"

    const val shapeView = "com.github.getActivity:ShapeView:8.0"

    const val xToast = "com.github.getActivity:XToast:8.5"

    const val appUtils = "com.blankj:utilcodex:1.30.6"

    const val apng = "com.moorgen.controls:apng:2.7.5.1"
    // 屏幕适配框架
    const val autoSize = "me.jessyan:autosize:1.2.1"

    const val picasso = "com.squareup.picasso:picasso:2.71828"
    // 微信分享
    const val wechat_open_sdk = "com.tencent.mm.opensdk:wechat-sdk-android-without-mta:5.5.8"

    const val eventBus = "org.greenrobot:eventbus:3.2.0"
    const val eventBusAnnotationProcessor ="org.greenrobot:eventbus-annotation-processor:3.2.0"

    const val statusBarCompat = "qiu.niorgai:statusbarcompat:0.0.4"

    const val swipeBack =  "cn.bingoogolapple:bga-swipebacklayout:1.2.0"

    //   权限动态申请
    const val hjqPermission = "com.hjq:xxpermissions:9.2"

    //   二维码
    const val zxing = "com.google.zxing:core:3.3.0"
    //统计图表
    const val chart = "com.github.PhilJay:MPAndroidChart:v3.1.0"


    // 适配android 9.0 对非公开API的限制
    const val fressReflect = "me.weishu:free_reflection:2.2.0"

    const val refreshLayout =   "com.scwang.smart:refresh-layout-kernel:${Versions.smartRefresh}"
    const val refreshHead =   "com.scwang.smart:refresh-header-material:${Versions.smartRefresh}"
    const val refreshFoot =   "com.scwang.smart:refresh-footer-classics:${Versions.smartRefresh}"

    var smartRefresh = arrayListOf(
        refreshLayout,refreshHead,refreshFoot
    )

    const val  exoplayer = "com.google.android.exoplayer:exoplayer:${Versions.exoplayer}"
    const val  exoplayer_core  = "com.google.android.exoplayer:exoplayer-core:${Versions.exoplayer}"

    var googleExoPlayer = arrayListOf(
        exoplayer,exoplayer_core
    )

    const val calendarview = "com.github.prolificinteractive:material-calendarview:2.0.1"
    const val threetenabp =  "com.jakewharton.threetenabp:threetenabp:1.1.1"

    var material_calendarview = arrayListOf(
        calendarview,threetenabp
    )

    const val bugly = "com.tencent.bugly:crashreport:latest.release"
    const val buglyNative = "com.tencent.bugly:nativecrashreport:3.8.0"
    const val tencentMap = "com.tencent.map.geolocation:TencentLocationSdk-openplatform:7.3.0"

    var tencentBugly = arrayListOf(
        bugly, buglyNative
    )

    const val touchregion = "com.wx.touchregion:touchregion:1.0.0"

    // Latest version is 5.0.x, using + to get the latest available
    const val linphoneSdk  = "org.linphone:linphone-sdk-android:5.0+"
    // Adding this dependency allows the linphone-sdk to automatically handle audio focus
    const val mediax = "androidx.media:media:1.1.0"

    var  linphoneAndroid= arrayListOf(
        linphoneSdk, mediax
    )

    const val arouter = "com.alibaba:arouter-api:${Versions.arouter}"
    const val arouterApt = "com.alibaba:arouter-compiler:${Versions.arouter}"

    // so 加载库
    const val relinker= "com.getkeepsafe.relinker:relinker:1.4.1"

    const val lich_savedstate =  "com.linecorp.lich:savedstate:2.6.0"
    const val lich_savedstate_ksp = "com.linecorp.lich:savedstate:2.6.0"

    const val haibin_calendarView = "com.haibin:calendarview:3.7.1"

    const val boost_multidex =  "com.bytedance.boost_multidex:boost_multidex:1.0.1"

    const val viewpager2 = "androidx.viewpager2:viewpager2:1.0.0"

    const val fresco = "com.facebook.fresco:fresco:2.2.0"

    const val gson = "com.google.code.gson:gson:2.8.5"
    const val commonsIo = "commons-io:commons-io:2.6"
    const val apacheCommonsIo = "org.apache.commons:commons-io:1.3.2"

    const val rxjava = "io.reactivex.rxjava2:rxjava:2.2.19"
    const val rxandroid = "io.reactivex.rxjava2:rxandroid:2.1.1"

    const val aaChart = "com.github.AAChartModel:AAChartCore-Kotlin:7.2.0"
}