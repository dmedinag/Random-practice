'''
Takes a list in the format specified in the examples at the bottom and returns a regex as shown.
'''
def build_regex(req):
    if (type(req) != list and type(req) != str):
        print('Error: Incompatible types')
        return -1
    if type(req) == list and len(req) % 2 != 1:
        print("Even length, missing an or somewhere")
        return -1

    if type(req) == str:
        return req
    if len(req) == 1:
        return build_regex(req[0])
    if type(req[0]) == list:
        return '(' + build_regex(req[0]) + '|' + build_regex(req[2:]) + ')'
    if type(req[0]) == str:
        return '(' + req[0] + '|' + build_regex(req[2:]) + ')'

    print("Error: Incompatible element types.")
    print("Required str or list, found " + type(req[0]))
    return -1


req = ['otro', 'or', 'calotro']
build_regex(req) # (otro|calotro)
req = ['uno', 'or', ['otro', 'or', 'calotro']]
build_regex(req) # (uno|(otro|calotro))
req = [['otro', 'or', 'calotro'], 'or', ['todo', 'or', 'toro']]
build_regex(req) # ((otro|calotro)|(todo|toro))
