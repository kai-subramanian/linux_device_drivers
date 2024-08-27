cmd_/home/kailash/hello_world/modules.order := {   echo /home/kailash/hello_world/hello.ko; :; } | awk '!x[$$0]++' - > /home/kailash/hello_world/modules.order
