# UmaExplorer

For exploring, debugging and modifying ウマ娘プリティーダービー (Umamusume Pretty Derby) with UI interface.

## Usage

Theoretically this should support "modern" versions of Windows, as long as it is x64. But this is only tested with Windows 10 v2004.

Please make sure that you have installed the latest Visual C++ 2019 Redistributable, otherwise the game would crash at start up time with no message at all.

1. Copy `version.dll` to the same directory with `umamusume.exe`. This should be `%USERPROFILE%\Umamusume` unless you did some magic yourself.
2. Start the game as usual (i.e., with DMM launcher).

## Build

0. Install [vcpkg](https://vcpkg.io/en/getting-started.html), and make sure to enable VS integration by running `vcpkg integrate install`.
1. `git clone`
2. Spin up Visual Studio 2019
3. Make sure everything is OK, and press "Build".

## Credits

This module is largely copied from [EXNOA-CarrotJuicer](https://github.com/CNA-Bld/EXNOA-CarrotJuicer).
