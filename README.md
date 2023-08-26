# acync_test
#
# 共有ライブラリのビルド
#   gcc -shared -fPIC -o libMyThread.so myThread.c
# mainのビルド
#   gcc test.c -L./ -lMyThread -lpthread -o test
#
#   myThread には非同期の API myAsync があり callback を引数に持っている。
#   myAsync は呼ばれたらスレッドを生成して(このとき、callback ポインタをスレッドに渡す)即時リターンする。
#   スレッドは生成されて5秒ほど待ったら callback を呼んでリターンする。
#
#   main 側には次の2つのコールバックがある
#       myCB1, myCB2
#   
#   また、連続して myAsync を呼び出し(このとき、callback は myCB1, myCB2 と変更しながら呼び出す)
#   2回の myAsync 呼び出しから戻った後、callback が呼ばれることを確認する。
#
#   git
#   git add -A
#   git commit -m "first commit"
#   git branch -M main
#   git remote add origin https://github.com/room6502/async_test.git
#   git push -u origin main
#
#


