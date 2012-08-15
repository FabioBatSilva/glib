G
=============
The gtkforphp g extension provides some base objects for use with all glib and gobject extensions.
This includes structs wrapped as "strict" PHP classes, enum objects, exceptions for gerror
handling, string and unicode string classes.

These types can be used on their own, but this extension also is used by almost all other
gtkforphp extensions.  Additional items maybe added later

You can send comments, patches, questions [here on github](https://github.com/gtkforphp/g/issues)

This is still an experimental extension.

Installing/Configuring
======================

This extension requires glib development files.  You can build the package
manually or use your system's package manager.  For example on ubuntu use

<pre>
apt-get install libglib-2.0-dev
</pre>

Then you can use phpize to install the extension against your current PHP install

<pre>
phpize
./configure
make && make test && make install
</pre>

If you want to use a non-standard location for your PHP use
<pre>
/path/to/phpize
./configure --with-php-config=/path/to/php-config
make && make test && make install
</pre>

`make install` copies `g.so` to the right location, but you still need to enable the module
in your php.ini file.  Although the extension can be used with a webserver, it's recommended
you only use this with a cli PHP install.