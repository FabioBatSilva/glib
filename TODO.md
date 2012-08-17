TODO
===

 1. error.c - Exception class needs to be set up right to be extendable and throwable from userland (with a gerror underneath)
              this will require some very fancy wiggling.  Perhaps better would be a way to translate
              a g\exception to a gerror 
 1. error.c   Also need to add constructor and tostring methods to the class