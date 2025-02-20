// SPDX-License-Identifier: MIT
// Copyright (c) 2015-2020 Zig Contributors
// This file is part of [zig](https://ziglang.org/), which is MIT licensed.
// The MIT license requires this copyright notice to be included in all copies
// and substantial portions of the software.
const std = @import("../std.zig");
const CpuFeature = std.Target.Cpu.Feature;
const CpuModel = std.Target.Cpu.Model;

pub const Feature = enum {
    @"64bit",
    a,
    c,
    d,
    e,
    experimental_b,
    experimental_v,
    experimental_zbb,
    experimental_zbc,
    experimental_zbe,
    experimental_zbf,
    experimental_zbm,
    experimental_zbp,
    experimental_zbproposedc,
    experimental_zbr,
    experimental_zbs,
    experimental_zbt,
    f,
    m,
    no_rvc_hints,
    relax,
    reserve_x1,
    reserve_x10,
    reserve_x11,
    reserve_x12,
    reserve_x13,
    reserve_x14,
    reserve_x15,
    reserve_x16,
    reserve_x17,
    reserve_x18,
    reserve_x19,
    reserve_x2,
    reserve_x20,
    reserve_x21,
    reserve_x22,
    reserve_x23,
    reserve_x24,
    reserve_x25,
    reserve_x26,
    reserve_x27,
    reserve_x28,
    reserve_x29,
    reserve_x3,
    reserve_x30,
    reserve_x31,
    reserve_x4,
    reserve_x5,
    reserve_x6,
    reserve_x7,
    reserve_x8,
    reserve_x9,
    save_restore,
};

pub usingnamespace CpuFeature.feature_set_fns(Feature);

pub const all_features = blk: {
    const len = @typeInfo(Feature).Enum.fields.len;
    std.debug.assert(len <= CpuFeature.Set.needed_bit_count);
    var result: [len]CpuFeature = undefined;
    result[@enumToInt(Feature.@"64bit")] = .{
                     .llvm_name = "64bit",
                     .description = "Implements RV64",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.a)] = .{
                     .llvm_name = "a",
                     .description = "'A' (Atomic Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.c)] = .{
                     .llvm_name = "c",
                     .description = "'C' (Compressed Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.d)] = .{
                     .llvm_name = "d",
                     .description = "'D' (Double-Precision Floating-Point)",
                     .dependencies = featureSet(&[_]Feature{
                                      .f,
                     }),
    };
    result[@enumToInt(Feature.e)] = .{
                     .llvm_name = "e",
                     .description = "Implements RV32E (provides 16 rather than 32 GPRs)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_b)] = .{
                     .llvm_name = "experimental-b",
                     .description = "'B' (Bit Manipulation Instructions)",
                     .dependencies = featureSet(&[_]Feature{
                                      .experimental_zbb,
                                      .experimental_zbc,
                                      .experimental_zbe,
                                      .experimental_zbf,
                                      .experimental_zbm,
                                      .experimental_zbp,
                                      .experimental_zbr,
                                      .experimental_zbs,
                                      .experimental_zbt,
                     }),
    };
    result[@enumToInt(Feature.experimental_v)] = .{
                     .llvm_name = "experimental-v",
                     .description = "'V' (Vector Instructions)",
                     .dependencies = featureSet(&[_]Feature{
                                      .f,
                     }),
    };
    result[@enumToInt(Feature.experimental_zbb)] = .{
                     .llvm_name = "experimental-zbb",
                     .description = "'Zbb' (Base 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_zbc)] = .{
                     .llvm_name = "experimental-zbc",
                     .description = "'Zbc' (Carry-Less 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_zbe)] = .{
                     .llvm_name = "experimental-zbe",
                     .description = "'Zbe' (Extract-Deposit 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_zbf)] = .{
                     .llvm_name = "experimental-zbf",
                     .description = "'Zbf' (Bit-Field 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_zbm)] = .{
                     .llvm_name = "experimental-zbm",
                     .description = "'Zbm' (Matrix 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_zbp)] = .{
                     .llvm_name = "experimental-zbp",
                     .description = "'Zbp' (Permutation 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_zbproposedc)] = .{
                     .llvm_name = "experimental-zbproposedc",
                     .description = "'Zbproposedc' (Proposed Compressed 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_zbr)] = .{
                     .llvm_name = "experimental-zbr",
                     .description = "'Zbr' (Polynomial Reduction 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_zbs)] = .{
                     .llvm_name = "experimental-zbs",
                     .description = "'Zbs' (Single-Bit 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.experimental_zbt)] = .{
                     .llvm_name = "experimental-zbt",
                     .description = "'Zbt' (Ternary 'B' Instructions)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.f)] = .{
                     .llvm_name = "f",
                     .description = "'F' (Single-Precision Floating-Point)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.m)] = .{
                     .llvm_name = "m",
                     .description = "'M' (Integer Multiplication and Division)",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.no_rvc_hints)] = .{
                     .llvm_name = "no-rvc-hints",
                     .description = "Disable RVC Hint Instructions.",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.relax)] = .{
                     .llvm_name = "relax",
                     .description = "Enable Linker relaxation.",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x1)] = .{
                     .llvm_name = "reserve-x1",
                     .description = "Reserve X1",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x10)] = .{
                     .llvm_name = "reserve-x10",
                     .description = "Reserve X10",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x11)] = .{
                     .llvm_name = "reserve-x11",
                     .description = "Reserve X11",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x12)] = .{
                     .llvm_name = "reserve-x12",
                     .description = "Reserve X12",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x13)] = .{
                     .llvm_name = "reserve-x13",
                     .description = "Reserve X13",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x14)] = .{
                     .llvm_name = "reserve-x14",
                     .description = "Reserve X14",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x15)] = .{
                     .llvm_name = "reserve-x15",
                     .description = "Reserve X15",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x16)] = .{
                     .llvm_name = "reserve-x16",
                     .description = "Reserve X16",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x17)] = .{
                     .llvm_name = "reserve-x17",
                     .description = "Reserve X17",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x18)] = .{
                     .llvm_name = "reserve-x18",
                     .description = "Reserve X18",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x19)] = .{
                     .llvm_name = "reserve-x19",
                     .description = "Reserve X19",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x2)] = .{
                     .llvm_name = "reserve-x2",
                     .description = "Reserve X2",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x20)] = .{
                     .llvm_name = "reserve-x20",
                     .description = "Reserve X20",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x21)] = .{
                     .llvm_name = "reserve-x21",
                     .description = "Reserve X21",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x22)] = .{
                     .llvm_name = "reserve-x22",
                     .description = "Reserve X22",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x23)] = .{
                     .llvm_name = "reserve-x23",
                     .description = "Reserve X23",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x24)] = .{
                     .llvm_name = "reserve-x24",
                     .description = "Reserve X24",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x25)] = .{
                     .llvm_name = "reserve-x25",
                     .description = "Reserve X25",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x26)] = .{
                     .llvm_name = "reserve-x26",
                     .description = "Reserve X26",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x27)] = .{
                     .llvm_name = "reserve-x27",
                     .description = "Reserve X27",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x28)] = .{
                     .llvm_name = "reserve-x28",
                     .description = "Reserve X28",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x29)] = .{
                     .llvm_name = "reserve-x29",
                     .description = "Reserve X29",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x3)] = .{
                     .llvm_name = "reserve-x3",
                     .description = "Reserve X3",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x30)] = .{
                     .llvm_name = "reserve-x30",
                     .description = "Reserve X30",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x31)] = .{
                     .llvm_name = "reserve-x31",
                     .description = "Reserve X31",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x4)] = .{
                     .llvm_name = "reserve-x4",
                     .description = "Reserve X4",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x5)] = .{
                     .llvm_name = "reserve-x5",
                     .description = "Reserve X5",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x6)] = .{
                     .llvm_name = "reserve-x6",
                     .description = "Reserve X6",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x7)] = .{
                     .llvm_name = "reserve-x7",
                     .description = "Reserve X7",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x8)] = .{
                     .llvm_name = "reserve-x8",
                     .description = "Reserve X8",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.reserve_x9)] = .{
                     .llvm_name = "reserve-x9",
                     .description = "Reserve X9",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    result[@enumToInt(Feature.save_restore)] = .{
                     .llvm_name = "save-restore",
                     .description = "Enable save/restore.",
                     .dependencies = featureSet(&[_]Feature{}),
    };
    const ti = @typeInfo(Feature);
    for (result) |*elem, i| {
                     elem.index = i;
                     elem.name = ti.Enum.fields[i].name;
    }
    break :blk result;
};

pub const cpu = struct {
    pub const baseline_rv32 = CpuModel{
                     .name = "baseline_rv32",
                     .llvm_name = null,
                     .features = featureSet(&[_]Feature{
                                      .a,
                                      .c,
                                      .d,
                                      .f,
                                      .m,
                     }),
    };
    pub const baseline_rv64 = CpuModel{
                     .name = "baseline_rv64",
                     .llvm_name = null,
                     .features = featureSet(&[_]Feature{
                                      .@"64bit",
                                      .a,
                                      .c,
                                      .d,
                                      .f,
                                      .m,
                     }),
    };
    pub const generic_rv32 = CpuModel{
                     .name = "generic_rv32",
                     .llvm_name = "generic-rv32",
                     .features = featureSet(&[_]Feature{}),
    };
    pub const generic_rv64 = CpuModel{
                     .name = "generic_rv64",
                     .llvm_name = "generic-rv64",
                     .features = featureSet(&[_]Feature{
                                      .@"64bit",
                     }),
    };
    pub const rocket_rv32 = CpuModel{
                     .name = "rocket_rv32",
                     .llvm_name = "rocket-rv32",
                     .features = featureSet(&[_]Feature{}),
    };
    pub const rocket_rv64 = CpuModel{
                     .name = "rocket_rv64",
                     .llvm_name = "rocket-rv64",
                     .features = featureSet(&[_]Feature{
                                      .@"64bit",
                     }),
    };
    pub const sifive_e31 = CpuModel{
                     .name = "sifive_e31",
                     .llvm_name = "sifive-e31",
                     .features = featureSet(&[_]Feature{
                                      .a,
                                      .c,
                                      .m,
                     }),
    };
    pub const sifive_u54 = CpuModel{
                     .name = "sifive_u54",
                     .llvm_name = "sifive-u54",
                     .features = featureSet(&[_]Feature{
                                      .@"64bit",
                                      .a,
                                      .c,
                                      .d,
                                      .f,
                                      .m,
                     }),
    };
};
