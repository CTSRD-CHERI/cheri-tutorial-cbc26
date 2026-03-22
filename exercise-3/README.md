# Stack Corruption Mitigation Exercise

## Roadmap

* Compile a program vulnerable to stack corruption
  * Demonstrate the vulnerability
* Run the same program with linkage-based compartmentalisation
  * Show that the vulnerability is mitigated
* Use `gdb` to understand why the vulnerability is mitigated
  * Backtrace: `bt`
  * List compartments: `info compartments`

## Instructions

1. Make sure you are using a toolchain that supports compartmentalisation policies.
1. Run `make all` to build two versions of the vulnerable program---one normal and one compartmentalised.
2. Run the normal version with `./normal`.
   * What stack addresses do you see? Can you reach one from the other?
   * Can you successfully corrupt data in the caller's frame from the callee?
3. Run the compartmentalised version with `./compart`.
   * What stack addresses do you see? Can you reach one from the other?
   * It is impossible to corrupt data in the caller's frame from the callee. Why?

## References

CheriBSD manual: [`c18n(7)`](https://man.cheribsd.org/cgi-bin/man.cgi/c18n)
