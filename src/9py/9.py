def encode(msg: str) -> tuple[str, dict[str, str]]:
    if not msg:
        return "", {}

    freq = {}
    for char in msg:
        freq[char] = freq.get(char, 0) + 1

    q = [[freq, char] for char, freq in freq.items()]

    while len(q) > 1:

        q.sort(key=lambda x: x[0])

        left = q.pop(0)
        right = q.pop(0)

        new_node = [left[0] + right[0], left, right]
        q.append(new_node)

    codes = {}

    def mcodes(node, cur_code):
        if len(node) == 2:
            codes[node[1]] = cur_code
        else:
            mcodes(node[1], cur_code + "0")
            mcodes(node[2], cur_code + "1")

    if q:
        mcodes(q[0], "")

    en_msg = "".join(codes[char] for char in msg)

    return en_msg, codes


def decode(encoded: str, table: dict[str, str]) -> str:

    reverse_table = {code: char for char, code in table.items()}

    msg2 = ""
    cur_code = ""

    for bit in encoded:
        cur_code += bit
        if cur_code in reverse_table:
            msg2 += reverse_table[cur_code]
            cur_code = ""

    return msg2

def encode_file(p1, p2):
    with open(p1, 'r') as x:
        t = x.read()

    e, tbl = encode(t)

    with open(p2, 'w') as x:
        x.write(str(tbl) + '\n')
        x.write(e)

def decode_file(p1, p2):
    with open(p1, 'r') as x:
        t_line = x.readline().strip()
        e_data = x.readline().strip()

    t_dict = eval(t_line)
    orig = decode(e_data, t_dict)

    with open(p2, 'w') as x:
        x.write(orig)

encode_file('p1.txt', 'encoded.huff')
decode_file('encoded.huff', 'decoded.txt')
