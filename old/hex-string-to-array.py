#!/usr/bin/env python3
print(
    ", ".join(
        [
            "0x"
            + __import__("sys").argv[1][w]
            + __import__("sys").argv[1][w + 1]
            for w in range(
                0,
                len(__import__("sys").argv[1]),
                2,
            )
        ]
    )
)
