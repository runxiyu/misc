# Copyright (c) Drew DeVault
/\t.*\.so.*/ {
	n=split($1, p, "/")
	split(p[n], l, ".")
	lib=l[1]
	if (libs[lib] == "") {
		libs[lib] = 0
	}
	libs[lib] += 1
}
END {
	for (lib in libs) {
		print libs[lib] "\t" lib
	}
}
