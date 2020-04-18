rmdir C:\Users\Izmar\git\moduru\build\32bit /s /q

md C:\Users\Izmar\git\moduru\build\32bit

cd C:\Users\Izmar\git\moduru\build\32bit
conan install -s build_type=Debug -s arch=x86 -g cmake_multi ../../ moduru/0.1@izmar/dev
conan install -s build_type=Release -s arch=x86 -g cmake_multi ../../ moduru/0.1@izmar/dev
conan build ../../
conan create ../../ moduru/0.1@izmar/dev