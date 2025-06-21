## Downloading, configuring, and installing Qt on Linux.


#### > Using the apt Package Manager.

You can use the apt Package Management tool to download and install the Qt
package. 

To do so, issue the following command from a command line.

```
sudo apt install qtk-base-dev
```

Using this command, the Qt package may get installed into the following locations;

```
/usr/include/x86_64-linux-gnu/qt6
/usr/lib/x86_64-linux-gnu/qt6
```


#### > Downloading Qt from GitHub.

Alternatively, you can use git to download the Qt package from GitHub.

To do so, issue the following command from a command line. 

````
git clone git://code.qt.io/qt/qt5.git
````

Then, cd into the directory which the Qt package was just downloaded into and
invoke the following script;

```
./init-repository
```


#### > The cmake utility.

To get a feel for what the `cmake` utility can do, issue the following command from a
command line terminal;

```
cmake --help
```

This should generate the following output;

```
Usage

  cmake [options] <path-to-source>
  cmake [options] <path-to-existing-build>
  cmake [options] -S <path-to-source> -B <path-to-build>

Specify a source directory to (re-)generate a build system for it in the
current working directory.  Specify an existing build directory to
re-generate its build system.

Options
  -S <path-to-source>          = Explicitly specify a source directory.
  -B <path-to-build>           = Explicitly specify a build directory.
  -C <initial-cache>           = Pre-load a script to populate the cache.
  -D <var>[:<type>]=<value>    = Create or update a cmake cache entry.
  -U <globbing_expr>           = Remove matching entries from CMake cache.
  -G <generator-name>          = Specify a build system generator.
  -T <toolset-name>            = Specify toolset name if supported by
                                 generator.
  -A <platform-name>           = Specify platform name if supported by
                                 generator.
  --toolchain <file>           = Specify toolchain file
                                 [CMAKE_TOOLCHAIN_FILE].
  --install-prefix <directory> = Specify install directory
                                 [CMAKE_INSTALL_PREFIX].
  --project-file <project-file-name>
                               = Specify an alternate project file name.
  -Wdev                        = Enable developer warnings.
  -Wno-dev                     = Suppress developer warnings.
  -Werror=dev                  = Make developer warnings errors.
  -Wno-error=dev               = Make developer warnings not errors.
  -Wdeprecated                 = Enable deprecation warnings.
  -Wno-deprecated              = Suppress deprecation warnings.
  -Werror=deprecated           = Make deprecated macro and function warnings
                                 errors.
  -Wno-error=deprecated        = Make deprecated macro and function warnings
                                 not errors.
  --preset <preset>,--preset=<preset>
                               = Specify a configure preset.
  --list-presets[=<type>]      = List available presets.
  --workflow [<options>]       = Run a workflow preset.
  -E                           = CMake command mode.  Run "cmake -E" for a
                                 summary of commands.
  -L[A][H]                     = List non-advanced cached variables.
  -LR[A][H] <regex>            = Show cached variables that match the regex.
  --fresh                      = Configure a fresh build tree, removing any
                                 existing cache file.
  --build <dir>                = Build a CMake-generated project binary tree.
                                 Run "cmake --build" to see compatible
                                 options and a quick help.
  --install <dir>              = Install a CMake-generated project binary
                                 tree.  Run "cmake --install" to see
                                 compatible options and a quick help.
  --open <dir>                 = Open generated project in the associated
                                 application.
  -N                           = View mode only.
  -P <file>                    = Process script mode.
  --find-package               = Legacy pkg-config like mode.  Do not use.
  --graphviz=<file>            = Generate graphviz of dependencies, see
                                 CMakeGraphVizOptions.cmake for more.
  --system-information [file]  = Dump information about this system.
  --print-config-dir           = Print CMake config directory for user-wide
                                 FileAPI queries.
  --log-level=<ERROR|WARNING|NOTICE|STATUS|VERBOSE|DEBUG|TRACE>
                               = Set the verbosity of messages from CMake
                                 files.  --loglevel is also accepted for
                                 backward compatibility reasons.
  --log-context                = Prepend log messages with context, if given
  --debug-trycompile           = Do not delete the try_compile build tree.
                                 Only useful on one try_compile at a time.
  --debug-output               = Put cmake in a debug mode.
  --debug-find                 = Put cmake find in a debug mode.
  --debug-find-pkg=<pkg-name>[,...]
                               = Limit cmake debug-find to the
                                 comma-separated list of packages
  --debug-find-var=<var-name>[,...]
                               = Limit cmake debug-find to the
                                 comma-separated list of result variables
  --trace                      = Put cmake in trace mode.
  --trace-expand               = Put cmake in trace mode with variable
                                 expansion.
  --trace-format=<human|json-v1>
                               = Set the output format of the trace.
  --trace-source=<file>        = Trace only this CMake file/module.  Multiple
                                 options allowed.
  --trace-redirect=<file>      = Redirect trace output to a file instead of
                                 stderr.
  --warn-uninitialized         = Warn about uninitialized values.
  --no-warn-unused-cli         = Don't warn about command line options.
  --check-system-vars          = Find problems with variable usage in system
                                 files.
  --compile-no-warning-as-error= Ignore COMPILE_WARNING_AS_ERROR property and
                                 CMAKE_COMPILE_WARNING_AS_ERROR variable.
  --link-no-warning-as-error   = Ignore LINK_WARNING_AS_ERROR property and
                                 CMAKE_LINK_WARNING_AS_ERROR variable.
  --profiling-format=<fmt>     = Output data for profiling CMake scripts.
                                 Supported formats: google-trace
  --profiling-output=<file>    = Select an output path for the profiling data
                                 enabled through --profiling-format.
  -h,-H,--help,-help,-usage,/? = Print usage information and exit.
  --version,-version,/V [<file>]
                               = Print version number and exit.
  --help <keyword> [<file>]    = Print help for one keyword and exit.
  --help-full [<file>]         = Print all help manuals and exit.
  --help-manual <man> [<file>] = Print one help manual and exit.
  --help-manual-list [<file>]  = List help manuals available and exit.
  --help-command <cmd> [<file>]= Print help for one command and exit.
  --help-command-list [<file>] = List commands with help available and exit.
  --help-commands [<file>]     = Print cmake-commands manual and exit.
  --help-module <mod> [<file>] = Print help for one module and exit.
  --help-module-list [<file>]  = List modules with help available and exit.
  --help-modules [<file>]      = Print cmake-modules manual and exit.
  --help-policy <cmp> [<file>] = Print help for one policy and exit.
  --help-policy-list [<file>]  = List policies with help available and exit.
  --help-policies [<file>]     = Print cmake-policies manual and exit.
  --help-property <prop> [<file>]
                               = Print help for one property and exit.
  --help-property-list [<file>]= List properties with help available and
                                 exit.
  --help-properties [<file>]   = Print cmake-properties manual and exit.
  --help-variable var [<file>] = Print help for one variable and exit.
  --help-variable-list [<file>]= List variables with help available and exit.
  --help-variables [<file>]    = Print cmake-variables manual and exit.

Generators

The following generators are available on this platform (* marks default):
  Green Hills MULTI            = Generates Green Hills MULTI files
                                 (experimental, work-in-progress).
* Unix Makefiles               = Generates standard UNIX makefiles.
  Ninja                        = Generates build.ninja files.
  Ninja Multi-Config           = Generates build-<Config>.ninja files.
  Watcom WMake                 = Generates Watcom WMake makefiles.
  CodeBlocks - Ninja           = Generates CodeBlocks project files
                                 (deprecated).
  CodeBlocks - Unix Makefiles  = Generates CodeBlocks project files
                                 (deprecated).
  CodeLite - Ninja             = Generates CodeLite project files
                                 (deprecated).
  CodeLite - Unix Makefiles    = Generates CodeLite project files
                                 (deprecated).
  Eclipse CDT4 - Ninja         = Generates Eclipse CDT 4.0 project files
                                 (deprecated).
  Eclipse CDT4 - Unix Makefiles= Generates Eclipse CDT 4.0 project files
                                 (deprecated).
  Kate - Ninja                 = Generates Kate project files (deprecated).
  Kate - Ninja Multi-Config    = Generates Kate project files (deprecated).
  Kate - Unix Makefiles        = Generates Kate project files (deprecated).
  Sublime Text 2 - Ninja       = Generates Sublime Text 2 project files
                                 (deprecated).
  Sublime Text 2 - Unix Makefiles
                               = Generates Sublime Text 2 project files
                                 (deprecated).
```

From this, we can see that if one were to cd into the desired build directory and then issue
a command which is similar to the following;

```
cmake <src_dir>
```

then cmake should generate build files for the package and install them into the current working directory,
i.e. the desired build directory.

It is worth noting that `<src_dir>` denotes the directory which the package's source code resides in. This
directory should also contain a file called `CMakeLists.txt`. This is the file which the `cmake` utility
will take its instructions from, when it comes to generating the build files.

Furthermore, this directory can be completely diffrent from the build directory which cmake will put the
build files into.


#### > cmake project files - CMakeLists.txt

Shown below is an example of a `CMakeLists.txt` file.

```
cmake_minimum_required(

 VERSION
     3.16
)

project(

 QtExample 
 VERSION
     1.0.0
 LANGUAGES
     CXX
)

set(

 CMAKE_CXX_STANDARD
 17
)

set(

 CMAKE_CXX_STANDARD_REQUIRED 
 ON
)

set(

 CMAKE_MODULE_PATH

)

# Find particular packages.

find_package(

 Qt6
 REQUIRED COMPONENTS
     Core
     Widgets
)

qt_standard_project_setup()

qt_add_executable(

 QtExample1
 QtExample1.cpp
 CSMainWindow.cpp
)

target_link_libraries(

 QtExample1
 PRIVATE 
     Qt6::Core 
     Qt6::Widgets
)
```

Apart from being used to generate build files, `CMakeLists.txt` files can also be loaded in the Qt Creator
IDE, effectively as a project file.
