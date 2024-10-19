from xmlrpc import server

class XMLRPCServer():
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.server = server.SimpleXMLRPCServer((self.host, self.port))

    def register_function(self, function):
        self.server.register_function(function)

    def serve_forever(self):
        print(f"Server is running on {self.host}:{self.port}")
        self.server.serve_forever()

    
if __name__ == '__main__':
    def add(a, b):
        return a + b

    server = XMLRPCServer('localhost', 8000)
    server.register_function(add)
    server.serve_forever()
