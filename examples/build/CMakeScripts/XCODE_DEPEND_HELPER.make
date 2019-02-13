# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.hello_world_console.Debug:
/Users/yves/Projects/xtd/xtd/examples/build/hello_world_console/Debug/hello_world_console:\
	/usr/local/lib/libxtd.a\
	/usr/local/lib/libxtd.console.a\
	/usr/local/lib/libxtd.delegates.a\
	/usr/local/lib/libxtd.properties.a\
	/usr/local/lib/libxtd.strings.a
	/bin/rm -f /Users/yves/Projects/xtd/xtd/examples/build/hello_world_console/Debug/hello_world_console


PostBuild.hello_world_console.Release:
/Users/yves/Projects/xtd/xtd/examples/build/hello_world_console/Release/hello_world_console:\
	/usr/local/lib/libxtd.a\
	/usr/local/lib/libxtd.console.a\
	/usr/local/lib/libxtd.delegates.a\
	/usr/local/lib/libxtd.properties.a\
	/usr/local/lib/libxtd.strings.a
	/bin/rm -f /Users/yves/Projects/xtd/xtd/examples/build/hello_world_console/Release/hello_world_console


PostBuild.hello_world_console.MinSizeRel:
/Users/yves/Projects/xtd/xtd/examples/build/hello_world_console/MinSizeRel/hello_world_console:\
	/usr/local/lib/libxtd.a\
	/usr/local/lib/libxtd.console.a\
	/usr/local/lib/libxtd.delegates.a\
	/usr/local/lib/libxtd.properties.a\
	/usr/local/lib/libxtd.strings.a
	/bin/rm -f /Users/yves/Projects/xtd/xtd/examples/build/hello_world_console/MinSizeRel/hello_world_console


PostBuild.hello_world_console.RelWithDebInfo:
/Users/yves/Projects/xtd/xtd/examples/build/hello_world_console/RelWithDebInfo/hello_world_console:\
	/usr/local/lib/libxtd.a\
	/usr/local/lib/libxtd.console.a\
	/usr/local/lib/libxtd.delegates.a\
	/usr/local/lib/libxtd.properties.a\
	/usr/local/lib/libxtd.strings.a
	/bin/rm -f /Users/yves/Projects/xtd/xtd/examples/build/hello_world_console/RelWithDebInfo/hello_world_console




# For each target create a dummy ruleso the target does not have to exist
/usr/local/lib/libxtd.a:
/usr/local/lib/libxtd.console.a:
/usr/local/lib/libxtd.delegates.a:
/usr/local/lib/libxtd.properties.a:
/usr/local/lib/libxtd.strings.a:
