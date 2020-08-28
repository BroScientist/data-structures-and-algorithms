class Solution:
    def reformatDate(self, date: str) -> str:
        months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        # create a dictionary of month to string of number
        month_to_int = {}
        for i in range (0, len(months)):
            if (i < 9):
                s = "0" + str(i + 1)
                month_to_int[months[i]] = s
            else:
                month_to_int[months[i]] = str(i + 1);
        res = ""
        day, month, year = date.split(" ")
        
        # build the day string by taking every character in the input string until a non-digit char is reached
        day_string = ""
        i = 0
        while (day[i].isdigit()):
            day_string += str(day[i])
            i += 1
        if len(day_string) == 1:
            day_string = "0" + day_string
            
        return f"{year}-{month_to_int[month]}-{day_string}"
        
        
