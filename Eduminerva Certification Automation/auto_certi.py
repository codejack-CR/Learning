from PIL import Image, ImageDraw, ImageFont
import pandas as pd

csv_filepath = 'data/Eduminerva.csv'
PNG_FILE = 'certi_formats/template.png'
OVERFLOW_LENGTH = 34

csv_file = pd.read_csv(csv_filepath)
print(csv_file.head())

""""
roles = set()
for row in csv_file.itertuples(index=False):
    if row[1].upper().strip() == 'EXECUTIVE':
        for role in list(row[2].split(',')):
            roles.add(role.strip().upper())
print(roles)
"""

# Certi Image Location attributes (Mid of the space, alignment is center and anchor is mid-descender ... See docs https://pillow.readthedocs.io/en/stable/handbook/text-anchors.html#:~:text=An%20anchor%20is%20specified%20with,When%20drawing%20text%20with%20PIL.)
class Positions:
    name_loc = (1020, 700)
    role_loc_overflow = (1050, 797)
    role_loc = (1374, 797)
    pos_loc = (830, 870)
    year_loc = (1165, 1015)
    
"""
# Certi Type 4 attributes
class Type_4:
    name_loc = (1015, 709)
    type_loc = (832, 800)
    year_loc = (1149, 950)
"""

large_font = ImageFont.truetype('sanchez.ttf', 70)
small_font = ImageFont.truetype('sanchez.ttf', 35)
text_color = (14, 69, 115)

for row in csv_file.itertuples(index=False):
    # Here be multiple roles
    roles = row[2].split(',')
    i = 1
    for role in roles:
        role = role.title().strip()
        PDF_FILE = 'certis/Certificate_' + row[0].strip().title().replace(' ', '_') + str(i if i > 1 else '') + '.pdf'

        i += 1

        certi_image = Image.open(PNG_FILE)

        certi = ImageDraw.Draw(certi_image)

        # Insert Name
        certi.text(Positions.name_loc, row[0].strip().upper(), anchor = 'ms', fill=text_color, font=large_font, align='center')

        # Insert Position
        certi.text(Positions.pos_loc, row[1].strip().title(), anchor = 'md', fill=text_color, font=small_font, align='center')

        # Insert Year
        certi.text(Positions.year_loc, "2020-2021", anchor = 'md', fill=text_color, font=small_font, align='center')

        # Insert Department(s)
        if(len(role) < OVERFLOW_LENGTH):
            certi.text(Positions.role_loc, role, anchor = 'md', fill=text_color, font=small_font, align='center')
        else:
            certi.text(Positions.role_loc_overflow, role, anchor = 'ld', fill=text_color, font=small_font, align='center')

        if certi_image.mode == 'RGBA':
            certi_image = certi_image.convert('RGB')

        certi_image.save(PDF_FILE, 'PDF', resolution=100.0)

print('DONE')

"""
for row in type_4.itertuples(index=False):
    PNG_FILE = '4.png'
    PDF_FILE = 'certis/Certificate_' + row.Name.title().replace(' ', '_') + '.pdf'

    certi_image = Image.open(PNG_FILE)

    certi = ImageDraw.Draw(certi_image)

    # Insert Name
    certi.text(Type_4.name_loc, row.Name.upper(), anchor = 'ms', fill=text_color, font=large_font)

    # Insert Type
    certi.text(Type_4.type_loc, row.Type.upper(), anchor = 'ms', fill=text_color, font=small_font)

    # Insert Year
    certi.text(Type_4.year_loc, row.Session.upper(), anchor = 'ms', fill=text_color, font=small_font)

    if certi_image.mode == 'RGBA':
        certi_image = certi_image.convert('RGB')

    certi_image.save(PDF_FILE, 'PDF', resolution=100.0)
"""