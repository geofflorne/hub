#!/usr/bin/env python
import json
import os

from jinja2 import Environment, FileSystemLoader

env = Environment(loader=FileSystemLoader('.'))
template = env.get_template('can_values.c.j2')

with open('can_values.json', 'r') as json_file:
    can_values = json.load(json_file)

with open('can_values.c', 'w') as output_file:
    output_file.write(template.render(can_values, trim_blocks=True, lstrip_blocks=True))
