import re
import hashlib


def emptyHash():
    return hashlib.sha1()


def hashString(string):
    return hashlib.sha1(string.encode())


"""
(?:^|(?:^\s+))
Included before the pragma search in order to match the beginning of a line
or the beginning + any whitespace. Ignore the result of this capture.
Used to enforce that are no comments or anything else before the pragma.

(#pragma\sGLOBAL_ASM\((.*?)\))
1st Match = entire pragma line
2nd Match = pragma arguments
"""
pragmaRegex = r"(?:^|(?:^\s+))(#pragma\sGLOBAL_ASM\((.*?)\))"


def getPragmaMatches(fileText):
    matches = re.findall(pragmaRegex, fileText, flags=re.DOTALL | re.MULTILINE)
    return matches


# Arguments are processed outside of the regex to keep it simple
# and support any changes we may make in the future


def getPragmaArgs(argString):
    args = argString.split(",")
    args = map(lambda s: s.split("\"")[1], args)
    return list(args)


labelRegex = r"\b.+:"


def getLabels(fileText):
    matches = re.findall(labelRegex, fileText)
    return matches


def getAsmFunctions(fileText):
    matches = getLabels(fileText)
    return list(filter(lambda x: "lbl_" not in x, matches))


def getAsmFunctionBlock(fileText, label):
    data = []
    found = False
    for line in fileText.splitlines():
        if ":" in line:
            match = re.match(labelRegex, line)
            if match and match.group(0) == label:
                found = True
                continue
        if found:
            data.append(line.strip())
            if len(line) == 0:
                break
    return data


def filterBlockCode(block):
    return list(filter(lambda x: "/*" in x, block))


def codeLineToBytes(line):
    d = line.split()
    b = "0x" + "".join(d[3:7])
    return b


def blockToBytes(block):
    code = filterBlockCode(block)
    return list(map(codeLineToBytes, code))


def bytesToString(byteLine):
    return "opword" + " " + byteLine


funcTemplate = """extern "C" {
asm void {name}() {
nofralloc
{data}
}}"""

funcTemplateNoSig = """nofralloc
{data}"""


def writeCode(source, funcName, codeBytes, isGlobal, noSig):
    source += "\n"
    if noSig:
        t = funcTemplateNoSig
    else:
        t = funcTemplate.replace("{name}", funcName)
    bs = list(map(bytesToString, codeBytes))
    t = t.replace("{data}", "\n".join(bs))
    if not isGlobal:
        t = t.replace("asm void", "asm static void")
    source += t + "\n"

    return source


def error(text):
    print("Error during #pragma processing:")
    print(text)
    exit(69)
