rm -rf ~/.conan/data/moduru
rm -rf ~/git/moduru/build/Release/*
rm -rf ~/git/moduru/build/Debug/*

cd ~/git/moduru/build/Release

conan install -s build_type=Debug ../../ moduru/0.1@izmar/dev
conan build ../../

conan install -s build_type=Release ../../ moduru/0.1@izmar/dev
conan build ../../

Conan create ../../ moduru/0.1@izmar/dev
