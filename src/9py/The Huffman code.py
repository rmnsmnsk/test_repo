def encode(msg: str) -> tuple[str, dict[str, str]]:
    if not msg:
        return "", {}

    freq = {}
    for char in msg:
        freq[char] = freq.get(char, 0) + 1

    priority_queue = [[frequency, char] for char, frequency in freq.items()]

    while len(priority_queue) > 1:
        priority_queue.sort(key=lambda x: x[0])
        
        left_node = priority_queue.pop(0)
        right_node = priority_queue.pop(0)
        
        new_node = [left_node[0] + right_node[0], left_node, right_node]
        priority_queue.append(new_node)

    codes = {}
    
    def build_codes(node, cur_code):
        if len(node) == 2:
            codes[node[1]] = cur_code
        else:
            build_codes(node[1], cur_code + "0")
            build_codes(node[2], cur_code + "1")
    
    if priority_queue:
        build_codes(priority_queue[0], "")
    
    encoded_msg = "".join(codes[char] for char in msg)
    
    return encoded_msg, codes


def decode(encoded: str, table: dict[str, str]) -> str:
    reverse_table = {code: char for char, code in table.items()}
    
    decoded_msg = ""
    cur_code = ""
    
    for bit in encoded:
        cur_code += bit
        if cur_code in reverse_table:
            decoded_msg += reverse_table[cur_code]
            cur_code = ""
    
    return decoded_msg


def encode_file(input_path, output_path):
    with open(input_path, 'r') as input_file:
        text = input_file.read()
    
    encoded_text, huffman_table = encode(text)
    
    with open(output_path, 'w') as output_file:
        output_file.write(str(huffman_table) + '\n')
        output_file.write(encoded_text)


def decode_file(input_path, output_path):
    with open(input_path, 'r') as input_file:
        table_line = input_file.readline().strip()
        encoded_data = input_file.readline().strip()
    
    huffman_table = eval(table_line)
    original_text = decode(encoded_data, huffman_table)
    
    with open(output_path, 'w') as output_file:
        output_file.write(original_text)


encode_file('p1.txt', 'encoded.huff')
decode_file('encoded.huff', 'decoded.txt')
