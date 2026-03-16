class TranError(Exception):
    def __init__(self,errorCode=500000,message='tranError'):
        self.errorCode=errorCode
        self.message=message

    def __str__(self):
        return "[%d] %s" % (self.errorCode,self.message)
