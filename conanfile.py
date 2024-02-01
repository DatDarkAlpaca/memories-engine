import os
import shutil
from conan import ConanFile
from conan.tools.files import copy


class RadishRecipe(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'PremakeDeps'

    def requirements(self):
        self.requires('entt/3.13.0')
        self.requires('glm/cci.20230113')
        self.requires('glfw/3.3.8')
        self.requires('glad/0.1.36')
        self.requires('spdlog/1.13.0')

    def configure(self):
        self.options['glad'].gl_profile = 'core'
        self.options['glad'].gl_version = '4.5'
